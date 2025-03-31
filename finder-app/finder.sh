#!/bin/sh

filesdir=$1
searchstr=$2

if [ -z $1 ]; then
	echo "Files directory not provided"
	exit 1
fi

if [ -z $2 ]; then
	echo "Search string not provided"
	exit 1
fi



directoryy=$(dirname "$filesdir)")
filenamee=$(basename "$filesdir")

#echo "Files directory with filename-> $directoryy and filename-> $filenamee  and search string-> $2 are provided"

num_files=$(ls -1 $1 | wc -l)

num_occurences_str=$(grep -roh "$2" "$1" | wc -l)

echo  "The number of files are $num_files and the number of matching lines are $num_occurences_str"
#echo "Number of files:$num_files and num occurences $num_occurences_str"
