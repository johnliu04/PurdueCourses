#!/usr/local/bin/python3.7

# ######################################################
# # Author : < Yanjun Chen >
# # email : < chen2620@purdue.edu >
# # ID : < ee364f21 >
# # Date : < Aug 28, 2019 >
# # ######################################################

import os
import sys
import math

# Module level Variables.
# # ######################################################

def searchForNumber():
    n = '1'
    while True:
        check = int(n)
        for count in range(0,5):
            newn = str(int(n)*(count + 2))
            for i in range(len(newn)):
                for j in range(len(n)):
                    if n[j] == newn[i]:
                        break
                if not n[j] == newn[i]:
                    break
            if not n[j] == newn[i]:
                break
        if int(newn) == check * 6:
            break
        else:
            newnum = int(n)+1
            n = str(newnum)

    return int(n)


def calculateChain():
    list = []
    length = len(list)
    n = 1
    newlist = list

    while n <= 1000000:
        newn = n
        newlist.append(n)
        while newn > 1:
            if newn%2:
                newn = 3 * newn + 1
                newlist.append(newn)
            else:
                newn = int(newn/2)
                newlist.append(newn)
        if length < (len(newlist)):
            length = len(newlist)
            list = newlist
            newlist = []
            n+=1
        else:
            newlist = []
            n += 1

    return list

if __name__  == "__main__":
    #print(type(searchForNumber()),searchForNumber())
    print(calculateChain())