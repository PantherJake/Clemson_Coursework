#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
  string name;
  vector<double> *productivity; // productivity[t] is productivity during minutes t..t+1
  vector<double> *productivity_sum; // productivity_sum[t] = productivity up to time t
  double cutoff; // point in time by which 1/2 fraction of productivity is spent
  double tstart, tstop; // time range to be assigned to this student by our algorithm
};

vector<Student> S;

void read_input(void)
{
  ifstream input_file("productivity.txt");
  string next_line;
  while (getline(input_file, next_line)) { // read one line at a time
    istringstream input_line(next_line);
    //S.emplace_back(); // add new default-constructed student to end of vector S
    Student &new_student = S.back();
    input_line >> new_student.name;
    double d;
    new_student.productivity = new vector<double>;
    new_student.productivity_sum = new vector<double>;
    new_student.productivity_sum->push_back(0);
    while (input_line >> d) {
      new_student.productivity->push_back(d);
      new_student.productivity_sum->push_back(new_student.productivity_sum->back() + d);
    }
  }
  input_file.close();
}

// return total productivity of student s up to time t
double cumulative_productivity(Student &s, double t)
{
  int ipart = min((int)t, (int)s.productivity->size() - 1);
  double dpart = t - ipart;
  return s.productivity_sum->at(ipart) + dpart * s.productivity->at(ipart);
}

// return total productivity of a student from time t1 to time t2
double get_productivity(Student &s, double t1, double t2)
{
  return cumulative_productivity(s, t2) - cumulative_productivity(s, t1);
}

// binary search between times t1 and t2 to find the point in time when
// half of the productivity of student s (between t1 and t2) has been reached
// e.g., get_productivity(t1,answer) should be half of get_productivity(t1,t2)
double get_halfway_cutoff(Student &s, double t1, double t2)
{
  double prod = get_productivity(s, t1, t2) / 2;

  double t_mid = (t1 + t2) / 2;
  double q1 = get_productivity(s, t1, t_mid);
  double q3 = get_productivity(s, t_mid, t2);

while(s.productivity->at(t_mid) != prod) {
  q1 = get_productivity(s, t1, t_mid);
  q3 = get_productivity(s, t_mid, t2);

  if(q1 > q3) {
    t2 = t_mid;
    //t_mid = (t1 + t2) / 2;
  }
  else {
    t1 = t_mid;
    //t_mid = (t1 + t2) / 2;
  }
  t_mid = (t1 + t2) / 2;
}
return t_mid;
  // TBD: use binary search and the get_productivity() function to return an
  // answer here that is accurate to within a tolerance of 0.0001
  // (i.e., the correct cutoff should differ from yours by at most 0.0001)
}

// TBD: Re-order subarray of students S[s1..s2] so those it contains:
// elements with cutoff values < val
// followed by elements with cutoff values == val
// followed by elements with cutoff values > val
// for full credit, your approach should run "in place"
int partition(int s1, int s2, double val)
{
  vector<Student> temp;
  int ArrIndex = 0;

  for(int i = s1, j = s2 - s1; i <= s2 / 2  ||
                 j > s2 / 2; i++, j--) {
                   temp[ArrIndex] = S[i];
                   ArrIndex++;
                   temp[ArrIndex] = S[j];
                   ArrIndex++;
  }

  for(int i = s1; i < s2; ++i) {

  }


  // // for(int i = s1; i < s2; ++i) {
  // //   for(int j = s2; j > s1; --j) {
  // //     if(S[j].cutoff < val) {
  // //       temp = S[i];
  // //       S[i] = S[j];
  // //       S[j] = temp;
  // //     }
  // //     else if(S[j].cutoff > val) {
  // //       temp = S[j];
  // //       S[j] = S[i];
  // //       S[i] = temp;
  // //     }
  //   }
  // }
}

// TBD: return the cutoff value of the student at a given rank within the
// subarray S[s1..s2] (re-ordering the array is fine during the process)
// e.g., if rank==0, we want to return the minimum cutoff of S[s1..s2]
double quickselect(int s1, int s2, int rank)
{
  double min;
  for(int i = s1; i < s2; ++i) {

  }
}

// split time range t1...t2 across students S[s1...s2] (say, n of them), so each of the
// student time blocks represents >= 1/n of that student's total productivity
// over the range from t1...t2. Output of this function is an assignment of tstart
// and tstop for each of students S[s1...s2].
void solve(int s1, int s2, double t1, double t2)
{
  // Base case -- we've narrowed things down to a single student
  if (s1==s2) { S[s1].tstart = t1; S[s1].tstop = t2; return; }

  // Compute the halfway cutoffs for all the students in our current problem
  for (int i=s1; i<=s2; i++)
    S[i].cutoff = get_halfway_cutoff(S[i], t1, t2);

  // Find the median of the cutoff values of S[s1..s2]
  double median_cutoff = quickselect(s1, s2, (s2-s1)/2);

  // Partition students into two groups based on the median, using the same
  // function for partitioning you deveoped for quickselect
  partition(s1, s2, median_cutoff);

  // Now recursively call solve() on two appropriate "half-sized" subproblems
  int mid = (s1+s2)/2;
  solve (s1, mid, t1, median_cutoff);
  solve (mid+1, s2, median_cutoff, t2);
}

void test_quickselect(void)
{
  int N = 7;
  // Add N random students
  for (int i=0; i<N; i++) {
    //S.emplace_back();
    S[i].cutoff = drand48() + drand48() + drand48();
  }

  // sort S[1..7] and store results
  vector<double> sorted_results;
  for (int j=0; j<N; j++)
    sorted_results.push_back(S[j].cutoff);
  sort(sorted_results.begin(), sorted_results.end());
  cout << "\nTesting quickselect on array A (shown in sorted order):\n";
  for (int j=0; j<N; j++) {
    cout << j << ": " << setprecision(4) << sorted_results[j] << " ";
  }
  cout << "\n";

  // see if quickselect results match these
  for (int j=0; j<N; j++) {
    random_shuffle(S.begin(), S.end());
    cout << "\nshuffle(A[0..6]) is ";
    for (int j=0; j<N; j++) cout << j << ": " << S[j].cutoff << " ";
    cout << "\n";
    double v = quickselect(0, N-1, j);
    if (v == sorted_results[j])
      cout << "Rank " << j << " test succeeded!\n";
    else
      cout << "Error: quickselect for rank " << j << " gave " << v
	   << " instead of " << sorted_results[j] << "\n";
  }
}

int main(void)
{
  // Use this to make sure your quickselect code works, then comment it out...
  test_quickselect();
  return 0;

  read_input();

  int N = S.size();    // # students
  double T = 24*7*60;  // upper end of time range
  solve(0, N-1, 0, T); // compute tstart and tstop for each student

  // Print and check output
  for (int i=0; i<N; i++) {
    double P = get_productivity(S[i], S[i].tstart, S[i].tstop);
    double minP = get_productivity(S[i], 0, T) / N;
    cout << S[i].name << " assigned to time range ["
	 << S[i].tstart << ", " << S[i].tstop << "], with "
	 << P << " total productivity (ideally >= " << minP << ")\n";
    if (P < minP) {
      cout << "Error: total productivity in this range too low\n";
      return 0;
    }
    for (int j=0; j<i; j++)
      if (!(S[j].tstart >= S[i].tstop || S[i].tstart >= S[j].tstop)) {
	cout << "Error: this overlaps with the time range of " << S[j].name << "\n";
	return 0;
      }
  }
}
