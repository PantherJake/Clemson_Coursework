#!/bin/bash

# Gathers deliverables and compiles it into a neat zip archive for your convenience
anchor=$(dirname $(realpath $0)); # Root based on this file's position
directories=("Task_A" "Task_B" "Task_C"); # Where to search
ignore=("ERT_Users_Manual.pdf" "slides.02-05 (1).pdf"); # Things to ignore
for task in ${directories[@]}; do
	cd ${anchor}/${task};
	content=();
	# Pick up files with these extensions, ignoring files in the ignore list
	for file in `ls *.{pdf,c,h,cpp,hpp} 2>/dev/null`; do
		if [[ " ${ignore[*]} " == *" ${file} "* ]]; then
			continue;
		fi;
		content+=("${file}");
	done;
	if [ ${#content} -gt 0 ]; then
		# Announce inclusion and COPY it to the root directory
		echo "Including submission content for ${task}:";
		for file in ${content[@]}; do
			echo -e "\t${task}/${file} -> ${task}_${file}";
			cp ${file} ${anchor}/${task}_${file};
		done;
	else
		echo "Nothing to submit in ${task}";
	fi;
done;
# Return to root directory
cd ${anchor};
# Gather all files into zip file
ls *.{pdf,c,h,cpp,hpp} 2>/dev/null | xargs zip proj1_submission.zip;
# Clean up root directory
ls *.{pdf,c,h,cpp,hpp} 2>/dev/null | xargs rm;
# Announce completion instructions
echo "If any files were missed, you may manually add them using the following commands:";
echo -e "\tcp Task_*/<missing_file>   Task_*_<missing_file>;\n\tzip proj1_submission.zip   Task_*_<missing_file>;";
echo "Where * is the relevant task letter";
echo -e "\nPlease upload 'proj1_submission.zip' to Canvas as your assignment submission.";

