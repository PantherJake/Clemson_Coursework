# Instructions

Optimize the DGEMM.C, to use tiling algorithm. Attached slides in note section demonstrate the technique. (tip: use functions to make this super easy). Restrict tile size to be a power of 2, and (tile\_size)^2 < problem size so that things divide evenly. Bonus points if you can do uneven blocks without performance loss.

# Questions
1. What tile size is best for each problem size? 
2. How much closer we get to peak performance? 
3. Why does this method work? 
4. Find an event in `perf list` that can demonstrate the difference between the original implementation and your implementation. Record results for each and provide. 

# Submission
1. A c file containing optimized code and 
2. A pdf report containing answer to the questions
Save these files in the Task\_C folder and use the top-level submission script to collect your assignment for submission.

# Note

For this section of the project, you are not supposed to take help from others or any other external resources. Please refer to `slides.02-05 (1).pdf` if you need help.
