#!/usr/local/bin/python3.7

#######################################################
#    Author:      <Yanjun Chen >
#    email:       <chen2620 >
#    ID:          <ee364f21 >
#    Date:        <8/27/2019 >
#######################################################

import glob
import os
from datetime import datetime

#helper function
def readfile(symbol):
    try:
        with open(symbol+'.dat', 'r') as f:
            string = f.readlines()[2:]
    except IOError:
        return
    return string

#returns the date with the biggest difference (1)
def getMaxDifference(symbol):
    string = readfile(symbol)
    if string == None:
        return
    difference = 0
    date = 0

    for infor in string:
        infor = infor.split(',')
        value=abs(float(infor[4])-float(infor[5]))
        if value > difference:
            difference = value
            date = infor[0]
    return date

#percentage of days (2)
def getGainPercent(symbol):
    string = readfile(symbol)
    if string == None:
        return
    totaldate = len(string)
    date = 0

    for infor in string:
        infor = infor.split(',')
        if float(infor[1])>float(infor[3]):
            date += 1

    return round(100*(date/totaldate),4)

#total volume from date1 to date2 (3)
def getVolumeSum(symbol, date1, date2):
    helpdate1 = date1.split('/')
    helpdate2 = date2.split('/')
    helpdate1 = datetime(int(helpdate1[0]), int(helpdate1[1]), int(helpdate1[2]))
    helpdate2 = datetime(int(helpdate2[0]), int(helpdate2[1]), int(helpdate2[2]))
    if helpdate1 >= helpdate2:
        return

    string = readfile(symbol)
    if string == None:
        return

    find1 = 0
    volume = 0
    for infor in string:
        infor = infor.split(',')
        if infor[0] == date2 and find1 == False:#first
            volume += float(infor[2])
            find1 = 1
        elif infor[0] == date1 and find1 == True:#last
            volume += float(infor[2])
            return int(volume)
        elif find1 == True:
            volume += float(infor[2])

    pass

#highestpositive gain percentage (4)
def getBestGain(date):
    list = []
    for filename in glob.glob(os.path.join('*.dat')):
        with open(filename, 'r') as f:
            string = f.readlines()[2:]
            list.append(string)

    Gain = 0
    for file in list:
        for infor in file:
            infor = infor.split(',')
            if infor[0] == date:
                gain = (float(infor[1])-float(infor[3]))*100/float(infor[3])
                if gain > Gain:
                    Gain = gain
                break
    return round(Gain,4)

#average price of the company’s stock over the given year (5)
def getAveragePrice(symbol, year):
    string = readfile(symbol)
    if string == None:
        return
    dailyave = 0
    count = 0

    for infor in string:
        years = infor[:4]
        infor = infor.split(',')
        if int(years) == year:
            dailyave += (float(infor[1])+float(infor[3]))/2
            count += 1
        elif count > 0:
            break
    #return format(dailyave/count,'.4f')
    return round(dailyave/count,4)

#number of days (6)
def getCountOver(symbol, price):
    string = readfile(symbol)
    if string == None:
        return
    count = 0

    for infor in string:
        infor = infor.split(',')
        if (float(infor[1])>=price and float(infor[3])>=price and float(infor[4])>=price and float(infor[5])>=price):
            count+=1
    return count

# # ######################################################
