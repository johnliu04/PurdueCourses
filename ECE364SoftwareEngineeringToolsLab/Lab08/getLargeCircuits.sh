# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620@purdue.edu >
# ID : < ee364f21 >
# Date : < 10/23/2019 >
# ######################################################
# Write your sequence of statements here .

(for circuit in $(ls "circuits/")
do 
  sizeoffile=$(wc -c circuits/$circuit | cut -f1 -d" ")
  if [[ $sizeoffile -ge 200 ]]
  then
    echo $circuit | cut -c 9-15
  fi
done | sort -u)

exit 0