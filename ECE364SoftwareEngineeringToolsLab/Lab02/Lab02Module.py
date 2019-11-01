#!/usr/local/bin/python3.7

#######################################################
#    Author:      <Yanjun Chen >
#    email:       <chen2620 >
#    ID:          <ee364f21 >
#    Date:        <9/4/2019 >
#######################################################

import os
import sys

Datapath = os.path.expanduser("~ee364/DataFolder/Lab02/")

def getLeastFrequent():
    listnum = []
    with open(Datapath+'numbers.dat', 'r') as f:
        matrix = f.readlines()
    for row in matrix:
        row = row.split(' ')
        for column in row:
            listnum.append(int(column))
    count = {listnum.count(a): a for a in listnum}
    freq,num = count.keys(),count.values()
    minfre = min(freq)
    result = count[minfre]
    return result

def getCodeFor(coordinate):
    list = []
    with open(Datapath+'coordinates.dat', 'r') as f:
        coord = f.readlines()[2:]
    for rows in coord:
        rows = rows.split()
        if coordinate == float(rows[0]) or coordinate == float(rows[1]):
            list.append(rows[2])

    return sorted(list)

def getSubMatrixSum(startRowIndex,endRowIndex,startColumnIndex,endColumnIndex):
    with open(Datapath+'numbers.dat', 'r') as f:
        matrix = f.readlines()
    list = []
    sum = 0
    for rows in (matrix[startRowIndex:endRowIndex]):
        rows = rows.split(' ')
        list+=(rows[startColumnIndex:endColumnIndex])
        #endColumnIndex
        list.append(rows[endColumnIndex])
    #endRowIndex
    rows = matrix[endRowIndex].split(' ')
    list+=rows[startColumnIndex:endColumnIndex]
    list.append(rows[endColumnIndex])
    for num in list:
        sum += int(num)

    return sum

if __name__  == "__main__":
    #print(getLeastFrequent())
    print(getCodeFor(-85.0707))
    print(getSubMatrixSum(97,97,97,97))