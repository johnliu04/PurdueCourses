# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/16/2019 >
# ######################################################
# Write your sequence of statements here .

x=0
y=0
for circuit in $(ls "circuits/")
do
  if [[ $(grep -i -E $1 circuits/$circuit) ]]
  then
    ((x++))
  fi
  if [[ $(grep -i -E $2 circuits/$circuit) ]]
  then
    ((y++))
  fi
done

if (( x > y ))
then
  echo $1
else
  echo $2
fi


exit 0