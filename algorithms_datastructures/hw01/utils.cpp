#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "stringintmap.h"
using namespace std;

StringIntMap clemsonWeb;
StringIntMap index;
//StringIntMap wordy;

//StringIntMap glossary;

// Returns entire file as one big string, quickly
string read_webpages_fast(const char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf (stderr, "Error: can't open %s", filename);
    exit(1);
  }
  fseek (fp, 0, SEEK_END);
  int size = ftell(fp);
  fseek (fp, 0, SEEK_SET);
  char *buff = new char[size+1];
  buff[size] = 0;
  int dummy_result = fread (buff, size, 1, fp);
  fclose (fp);
  string result(buff);
  delete [] buff;
  return result;
}

// Some ANSI terminal commands you can print to clear screen and change colors
string clear_screen = "\e[2J\e[H";
string color_red = "\e[31;40m";
string color_green = "\e[32;40m";
string color_yellow = "\e[33;40m";
string color_blue = "\e[34;40m";
string color_magenta = "\e[35;40m";
string color_cyan = "\e[36;40m";
string color_white = "\e[37;40m";
string color_whiteblue = "\e[37;44m";

Word* words;
Webpage* pages;

void predict(string query)
{
  //int x, y, z;
  cout << color_green << "Here is where query results for '"
       << color_white << query
       << color_green << "' should go\n";

       if(query == "") {
         cout << "NONE" << endl;
       }
       else if(index.find(query)) {
         cout << query << endl;
         int search = index[query];
         cout << color_cyan << "Pages containing: " << words[search].text << endl;

         for(int i = 0; (i < words[search].pages.size()) && (i < 10); ++i) {
           cout << color_red << i + 1 << ".  " << color_white << pages[words[search].pages[i]].weight << " " << pages[words[search].pages[i]].url << endl;
           cout << "\n";
         }
         cout << words[search].pages.size() << " pages found" << endl;
       }
       else {
         cout << "Whoops! Nothing here." << endl;
       }
}


void process_keystrokes(void)
{
  int ch = 0;
  string query;

  while (ch != '\n') {
    cout << clear_screen << color_green << "Search keyword: "
	 << color_white << query
	 << color_green << "-\n\n";

    predict(query);
    cout << flush;

    struct termios oldt, newt;
    tcgetattr (STDIN_FILENO, &oldt);
    newt = oldt; newt.c_lflag &= ~(ICANON|ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr (STDIN_FILENO, TCSANOW, &oldt);

    if (ch == 8 || ch == 127) { // backspace
      if (query.length() > 0) query = query.substr(0, query.length()-1);
    } else if (ch != ' ' && ch != '\n') query += ch;
  }
  cout << color_white;
}

/*bool pageComparison(int a, int b) {
  return pages[a].weight > pages[b].weight;
}*/

// This shows how to use some of the starter code above
int main(void)
{
  cout << color_green << "Reading input..." << endl;
  const char *filename = "/group/course/cpsc212/f20/hw01/webpages.txt";
  istringstream webfile (read_webpages_fast (filename));

  // For now, this just counts the number of web pages in the input file...
  string s;
  int N = 0;
  //int W = 0;

// FIRST SCAN

  while (webfile >> s) {
    if (s == "PAGE") {
      webfile >> s;
      clemsonWeb.insert(s, N); // s is the url of the webpage currently being processed
      N++;
    }
    else if(s == "LINK")
      webfile >> s;
    else {
      if(!index.find(s))
        index.insert(s, index.get_num_elems());
    }
  }

  //clemsonWeb.print();
  pages = new Webpage[N];
  // If you want to reset the webfile for reading again from the beginning...
  webfile.clear();
  webfile.seekg(0);
  N = -1;

  cout << "Building index..." << endl;
  //
  words = new Word[index.get_num_elems()];
  //
// SECOND SCAN

  while (webfile >> s) {
    if(s == "PAGE") {
      N++;
      webfile >> s;
      pages[N].url = s;
      pages[N].weight = 1;
    }
    else if(s == "LINK") {
      webfile >> s;
      if(clemsonWeb.find(s)) {
        pages[N].num_links++;
        pages[N].links.push_back(clemsonWeb[s]);
        //cout << pages[N].num_links << endl;
      }
    }
    else {
      string str;
      pages[N].num_words++;
      // Converts int to string
      stringstream ss;
      ss << s;
      ss >> str;
      pages[N].words.push_back(str);
      //cout << pages[N].num_words << endl;
      words[index[s]].pages.push_back(N);
    }
  }

  // Enter loop to ask for query
  for(int i = 0; i < 50; ++i) {
    for(int j = 0; j < N; ++j) pages[j].new_weight = 0.1;
    for(int q = 0; q < N; ++q) {
      if(pages[q].num_links == 0) pages[q].new_weight += 0.9 * pages[q].weight;
      else
      for(int x = 0; x < pages[q].num_links; ++x) pages[pages[q].links[x]].new_weight += 0.9 * pages[q].weight / pages[q].num_links;
    }
    for(int y = 0; y < N; y++) pages[y].weight = pages[y].new_weight;
  }

  process_keystrokes();

  return 0;
}
