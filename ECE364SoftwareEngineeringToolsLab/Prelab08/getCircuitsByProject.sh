# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/16/2019 >
# ######################################################
# Write your sequence of statements here .

file="maps/projects.dat"

#echo $1 ##Project ID
#grep -i -E $1 $file | cut -f5 -d" " | sort -u
grep -i -E $1 $file | cut -b 5-11 | sort -u

exit 0
