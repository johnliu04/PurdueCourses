#!/usr/local/bin/python3.7

# ######################################################
# # Author : < Yanjun Chen >
# # email : < chen2620@purdue.edu >
# # ID : < ee364f21 >
# # Date : < Aug 20, 2019 >
# # ######################################################

import os
import sys
import math

# Module level Variables.
# # ######################################################
Datapath = os.path.expanduser('~ee364/DataFolder/Prelab01/sequence.txt')

#find all possible sequences that match the given pattern (1)
def find(pattern):
    with open(Datapath, 'r') as f:
        string = f.readline()
    result=[] ##output list
    lenpat=len(pattern)
    lenstr=len(string)
    for i in range(lenstr):
        if i+lenpat >= lenstr:
            break
        consequence=string[i:(i+lenpat)]
        q = 0
        while q < lenpat:
            if pattern[q]=='X' or pattern[q]==consequence[q]:
                q += 1
            else:
                q = lenpat + 1
        if q == lenpat:
            result.append(consequence)
    return result

#find all sequences whose digital product is equal to product (2)
def getStreakProduct(sequence, maxSize, product):
    result=[]
    lengsequ=len(sequence)
    for l in range(lengsequ):
        seqproduct = int(sequence[l])
        for i in range(2, maxSize+1):
            if l+i-1 >= lengsequ:
                break
            seqproduct = seqproduct * int(sequence[l+i-1])
            if seqproduct >= product:
                if seqproduct == product:
                    result.append(sequence[l:l+i])
                break
    return result

#saves one or more pyramid-shaped sequence of characters in file (3)
def writePyramids(filePath, baseSize, count, char):
    space = int(baseSize/2)
    result = []

    for i in range(0, baseSize, 2):
        string = ''
        for l in range(space):
            string += ' '
        for l in range(i+1):
            string += char
        for l in range(space):
            string += ' '
        result.append(string)
        for l in range(count-1):
            result.append(' '+string)
        result.append('\n')
        space -= 1

    with open(filePath, 'w') as f:
        for item in result:
            f.write("%s"%item)
    pass

#show all letters meet found in the sequence (4)
def getStreaks(sequence, letters):
    result=[]
    i=0
    lengletter=len(letters)
    length=len(sequence)
    while i < length:
        for letter in range(lengletter):
            if sequence[i]==letters[letter]:
                break
        if sequence[i]==letters[letter] and i==length-1:
            result.append(sequence[i])
            i+=1
        elif sequence[i]==letters[letter]:
            for index in range(i+1,length):
                if sequence[index]!=sequence[i]:
                    break
            if index == length-1 and sequence[index] == sequence[i]:
                index+=1
            result.append(sequence[i:index])
            i = index
        else:
            i+=1
            while i < length and sequence[i-1]==sequence[i]:
                i+=1
    return result

#search for matched name in the namelist (5)
def findNames(nameList, part, name):
    result=[]
    name = name.capitalize()
    for i in nameList:
        testname = i.split()
        testname[0] = testname[0].capitalize()
        testname[1] = testname[1].capitalize()
        if part == 'L' and name == testname[1]:
            result.append(i)
        elif part == 'F' and name == testname[0]:
            result.append(i)
        elif (part=='FL') and (name==testname[0] or name==testname[1]):
            result.append(i)
    return result

#convert an integer to a list of Booleans (6)
def convertToBoolean(num, size):
    result = []
    if not (isinstance(num, int)) or not (isinstance(size, int)):
        return result #input parameters are not integers

    newnum = bin(num).replace("0b","")
    if len(newnum) < size:
        newnum='0'*(size-len(newnum))+newnum
    for i in newnum:
        if int(i) == True:
            result.append(True)
        else:
            result.append(False)
    return result

#convert a list of Booleans to integer(7)
def convertToInteger(boolList):
    newnum = ''
    if not (isinstance(boolList, list)):
        return #input is not a list
    if boolList==[]:
        return
    for item in boolList:
        if item == True:
            newnum += '1'
        elif item == False:
            newnum += '0'
        else:
            return
    newnum = int(newnum,2)
    return newnum

# # ######################################################