# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/23/2019 >
# ######################################################
# Write your sequence of statements here .

projectfile="maps/projects.dat"
studentfile="maps/students.dat"

#echo $1 ##Project ID
studentID=$(grep -i -E "$1" $studentfile | cut -f31 -d" ")
(for circuit in $(ls "circuits/")
do
  valid=$(grep "[0-9]\{5\}-" circuits/$circuit | grep $studentID)
  if [[ $valid ]]
  then
    grep -i "[A-Z]\{3\}-[0-9]\{3\}" circuits/$circuit | cut -c 3-
  fi
done | sort -u)

exit 0