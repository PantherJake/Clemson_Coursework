# Instructions

1. Run the following command: `./ert config.txt`. If you encounter permission problem, please run `chmod +x ert`. This will run the tool and produce results in a minute or two.
2. The results from the previous command are saved in a directory named `Results.cs.clemson.edu`, including a .ps file. Convert it to a pdf file using following command: `ps2pdf roofline.ps roofline.pdf`
3. Download it to your local system using scp: `scp `\<your\_username>`@access1.computing.clemson.edu:/`<your_project_directory>`/*.pdf` <output_file_name>

# Questions

The pdf file contains a graph. Refer to this graph and the included ERT Users Manual pdf to answer the following questions:

1. What does FLOPs/Byte mean?
2. Why are there two purple lines and what are the values?
3. What is the blue line? Why is it flat?
4. In simple terms, what does this graph tell us about the machine you ran the program on?

# Submission

Your submission should be a pdf report containing your answers to the questions mentioned above.
Save your pdf in the Task\_A folder and use the top-level submission script to collect your assignment for submission.

