# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/23/2019 >
# ######################################################
# Write your sequence of statements here .

projectfile="maps/projects.dat"

circuitsizes=$(for circuit in $(ls "circuits/")
do
  wc -c circuits/$circuit
done | sort -ru | head -1 | cut -c 22-28)
grep -i -E $circuitsizes $projectfile | cut -f15 -d" " | sort -u

exit 0