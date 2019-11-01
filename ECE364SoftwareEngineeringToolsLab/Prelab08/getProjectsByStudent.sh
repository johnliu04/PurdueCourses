# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/16/2019 >
# ######################################################
# Write your sequence of statements here .

projectfile="maps/projects.dat"
studentfile="maps/students.dat"

studentID=$(grep -i -E "$1" $studentfile | cut -f31 -d" ")

(for circuit in $(ls "circuits/")
do
  studentvalid=$(grep "[0-9]\{5\}-" circuits/$circuit | grep $studentID)
  if [[ $studentvalid ]]
  then
    circuitID=$(echo $circuit | cut -c 9-15)
    grep -i -E $circuitID $projectfile | cut -f15 -d" "
  fi
done | sort -u)

exit 0