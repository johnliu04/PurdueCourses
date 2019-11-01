# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/16/2019 >
# ######################################################
# Write your sequence of statements here .

x=0
for circuit in $(ls "circuits/")
do
  componentID=$(grep -i -E $1 circuits/$circuit)
  if [[ $componentID ]]
  then
    ((x++))
  fi
done

echo $x

exit 0