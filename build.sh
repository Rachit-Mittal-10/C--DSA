# !/bin/bash

if [ $# -eq 1 ]; then
	if [ -e "$1" ]; then
		filename=$(basename $1 .cpp)
		mkdir -p ./bin
		g++ "$1" -o "./bin/$filename"
		if [ -e "./bin/$filename" ]; then
			"./bin/$filename"
		fi
	else
		echo "No File Exist"
	fi
else
	echo "No File Provided"
fi
