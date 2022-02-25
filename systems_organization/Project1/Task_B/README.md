# Instructions

1. Run `make` in the Task B directory.
2. Command for running the output file using `./dgmake 4 1000 30 1`

Note: Here we are using 4 command line arguements:

   1. Number of threads to run (4)

   2. Problem Size (1000)

   3. Repeats (# of times to repeat the operation, Minimum value=30) (30)

   4. Enable / Disable Error checking (1 - True, 0 - False) (1 - True)
 
# Questions

1. Students should record the time required for 1,2,4,8 threads and problem size 2048, 4096, 8192 and plot it (with -O3).
2. For one thread, use perf to record cycles, instructions, clock rate (error-check disabled). Using the equation we learned in class, compute the time it should take to compute. Does it match the actual time?
3. Run it with two threads. Are the number of instructions different? Why? (error-check disabled)
4. Use amdahl's law to compute the theoretical maximum speedup for 4 threads. What % of the maximum did we achieve using 4 threads? (serial portion is computed by perf\_time\_output - "Multiply Time" from program output) (error check disabled!)
5. What percentage of peak performance did we reach? (refer Task A)
6. Record performance with each compiler flag: -g, -O0, -O1, -O2, -O3
7. Why are optimizations not turned on by default? Why are there levels of optimization? List two new optimizations at each level above 0; that is, two optimizations in O1 not in O0, two in O2 not in O1, two in O3 not in O2. 

# Submission
You should submit a pdf report containing answers to questions above.
Save your pdf in the Task\_B folder and use the top-level submission script to collect your assignment for submission.

# Note
Please do not forget to cite your sources, if you are referring to anything for help while answering the questions below.
