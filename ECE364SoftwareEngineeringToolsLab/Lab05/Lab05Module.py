#!/usr/local/bin/python3.7

# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620 >
# ID : < ee364f21 >
# Date : < 9/3/2019 >
# ######################################################

import os # List of module import statements
import sys # Each one on a line
from pprint import pprint as pp

def readdrivers():
    driverlist = {}
    with open('drivers.dat', 'r') as f:
        f.readline()
        cars = f.readline().split()
        f.readline()
        while (True):
            line = f.readline()
            if line == '':
                break
            line = line.replace('|','')
            driver = line.split()
            carlist = []
            driverinfor = driver[2:]
            for i in range(0,len(driverinfor)):
                if driverinfor[i] == 'X':
                    carlist.append(cars[i])
            driverlist[driver[0]+' '+driver[1]] = carlist
    return driverlist

def readcars():
    carID = []
    carName = []
    with open('cars.dat', 'r') as f:
        f.readline()
        f.readline()
        while (True):
            line = f.readline()
            if line == '':
                break
            line = line.split('|   ')
            car = line
            carID.append(car[0].split()[0])
            carName.append(car[1].replace('\n',''))
    return carID,carName

def getDriversFor(carID):
    result = set()
    driverlist = readdrivers()
    for driver,car in driverlist.items():
        if carID in car:
            result.add(driver)
    if result == set():
        raise ValueError("CarID doesnot exist")
    return result

def getCommonDriversFor(*args):
    driverlist = readdrivers()
    carID, carName = readcars()
    carids = []
    result = set()
    for arg in args:
        indexn = carName.index(arg)
        carids.append(carID[indexn])
    for key,value in driverlist.items():
        countn = 0
        for carid in carids:
            if carid in value:
                countn += 1
        if countn == len(carids):
            result.add(key)
    return result

def getCarsFor(names):
    driverlist = readdrivers()
    carID,carName = readcars()
    result = {}
    for name in names:
        carlist = driverlist[name]
        carname = []
        for carid in carlist:
            i = carID.index(carid)
            carname.append(carName[i])
        result[name] = set(carname)
    return result

def readsignals():
    signaldic = {}
    with open('signals.dat', 'r') as f:
        signals = f.readline().split()
        for signal in signals:
            signaldic[signal] = []
        f.readline()
        while (True):
            line = f.readline()
            if line == '':
                break
            time = line.split()
            i = 0
            for signal in signals:
                signaldic[signal].append(float(time[i]))
                i += 1
    return signaldic

def getBounds():
    signaldic = readsignals()
    result = {}
    for key,value in signaldic.items():
        if (key == 'Time'):
            pass
        else:
            minvalue = min(value)
            minvalue = round(minvalue,3)
            maxvalue = max(value)
            maxvalue = round(maxvalue,3)
            averagevalue = sum(value)/len(value)
            averagevalue = round(averagevalue,3)
            result[key] = (minvalue,averagevalue,maxvalue)
    return result

def getSampled(name):
    signaldic = readsignals()
    i = []
    result = []
    times = signaldic['Time']
    for time in times:
        if int(time) == time:
            i.append(times.index(time))
    try:
        signals = signaldic[name]
    except:
        raise ValueError("name doesnot exist")
    for idex in i:
        result.append(signals[idex])
    return result

def getDuration(start,end):
    signaldic = readsignals()
    times = signaldic['Time']
    starti = times.index(start)
    endi = times.index(end)
    result = {}
    for key, value in signaldic.items():
        if (key == 'Time'):
            pass
        else:
            result[key] = value[starti:endi+1]
    return result

def getValueAt(name,timestamp):
    signaldic = readsignals()
    times = signaldic['Time']
    signal = signaldic[name]
    try:
        indexn = times.index(timestamp)
    except:
        a = 9999999999999999999999999999
        for time in times:
            value = abs(time-timestamp)
            if value < a:
                a = value
                target = time
        indexn = times.index(target)
    return signal[indexn]

def getLargest(rectangles):
    rectangledata = {}
    with open('rectangles.dat', 'r') as f:
        f.readline()
        f.readline()
        f.readline()
        f.readline()
        while (True):
            line = f.readline()
            if line == '':
                break
            line = line.replace(',','')
            infor = line.split()
            rectangledata[infor[0]] = []
            tupleinfor = (float(infor[1]),float(infor[2]))
            rectangledata[infor[0]].append(tupleinfor)
            tupleinfor = (float(infor[3]), float(infor[4]))
            rectangledata[infor[0]].append(tupleinfor)
    maxarea = 0
    for rectangele in rectangles:
        points = rectangledata[rectangele]
        x1,y1 = points[0]
        x2,y2 = points[1]
        area = (x2-x1)*(y2-y1)
        if area > maxarea:
            maxarea = area
            result = rectangele
    return result

if __name__  == "__main__":
    #q1 = getDriversFor('C-583')
    #if ('Uribe, Floria' in q1):
        #print("yes\n")
    #print(type(q1))

    q2 = getCommonDriversFor('Mercedes Sprinter','Honda Accord','Ford Focus')
    print(q2)
    print(len(q2))

    #q3 = getCarsFor({'Sang, Chanell','Chock, Velvet'})
    #pp(q3)

    #q4 = getBounds()
    #print(type(q4))
    #pp(q4)

    #q5 = getSampled('ISO610')
    #print(q5,len(q5))
    #print(type(q5))

    #q6 = getDuration(1.0,2.0)
    #print(q6['AFW481'])
    #print(type(q6))

    #q7 = getValueAt('XDF846',15.817)
    #print(q7)
    #print(type(q7))

    #q8 = getLargest({'R034','R016','R066','R118','R026','R045'})
    #print(q8,type(q8))
    pass