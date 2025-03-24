# !/bin/bash

if [ $# -eq 1 ]; then
	if [ -e "$1" ]; then
		code "$1"
	else
		touch "$1"
		code "$1"
		# echo "No File Exist"
	fi
else
	echo "No File Provided"
fi
