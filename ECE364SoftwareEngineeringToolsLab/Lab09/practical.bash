#! /bin/bash

#----------------------------------
# $Author: ee364f21 $ Yanjun Chen
# $Date: 2019-10-29 19:33:52 -0400 (Tue, 29 Oct 2019) $ 10.29
#----------------------------------

function part_1 
{               
    # Fill out your answer here. Do not include exit 0 in your code.
    cat file.txt | sort | uniq -d
    return                      
}                               

function part_2
{              
    # Fill out your answer here. Do not include exit 0 in your code.
    count=0

    for item in $(cat temp.txt)
    do
      if [[ ${#item} -ge 10 ]]
      then
	 ((count++))
      fi
    done

    echo "temp.txt has $count lines with at least length ten"
    return                     
}                              

function part_3
{
    # Fill out your answer here. Do not include exit 0 in your code.
    egrep -c "PURDUE" info.txt
    return
}


# To test your function, you can call it below like this:
#
#part_1
#part_2
#part_3
