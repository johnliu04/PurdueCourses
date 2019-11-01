# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/16/2019 >
# ######################################################
# Write your sequence of statements here .

projectfile="maps/projects.dat"
studentfile="maps/students.dat"

#echo $1 ##Project ID
circuits=$(grep -i -E $1 $projectfile | cut -f5 -d" ")
(for circuit in $circuits
do
  nameIDs=$(grep "[0-9]\{5\}-" circuits/circuit_$circuit.dat)
  for nameID in $nameIDs
  do
    grep -i -E $nameID $studentfile | cut -f1 -d"|"
  done
done | sort -u)
exit 0
