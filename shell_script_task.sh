
#-------   Program Task   ------------

# Author Name        : V.kaviyarasu

# Submission Date    : 13-oct-2021

# Shell Script Program    : Provided a input file, every alternate lines needs to be swapped i.e 2nd line should be moved as 1st and 1st line as 2nd and so on until end of the file.

#----      Comment EOD   ---------



#------START----------

#!/bin/bash

# defining array for store line by line  in the input file

declare -a myArray

#for storing each line in each index to the array
index=0

#taking the entered file  path or name to be store in variable

read  -p "Enter the file name : " file_name

#functioning every line to be stored sequentially in array

while read -r line;
do
	myArray[$index]=$line
        index=$(expr $index + 1)
done <"$file_name"



#taking initial value for start the while loop and increment within the loop until it gets fail
count=0

#defining every alternate line swap
#the while loop will display the two line swap each time
 
while [ $count -lt $index ]

do
	count=$(expr $count + 2)
	line=$count
	line=$(expr $line - 1)
	echo "${myArray[$line]}"
	line=$(expr $line - 1)
	echo "${myArray[$line]}"
done


#------------END-------------------
