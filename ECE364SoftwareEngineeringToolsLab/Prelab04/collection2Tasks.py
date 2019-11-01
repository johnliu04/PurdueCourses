#!/usr/local/bin/python3.7

# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620 >
# ID : < ee364f21 >
# Date : < 9/3/2019 >
# ######################################################

import os # List of module import statements
import sys # Each one on a line
import glob
from collections import namedtuple
from pprint import pprint as pp

##helper function
def readtechniciansfile():
    with open('maps/technicians.dat', 'r') as f:
        techs = f.readlines()[2:]
    techlist = []
    Tech = namedtuple("Tech", ["name", "ID"])
    for tech in techs:
        tech = tech.split()
        techlist.append(Tech(str(tech[0]+' '+tech[1]),tech[3]))
    return techlist

def getTechnicianID(techname,techid):
    techlist = readtechniciansfile()
    targettechname = []
    targettechID = []
    if (techid is None): #return ID
        for tech in techlist:
            if tech.name in techname:
                targettechID.append(tech.ID)
                break
    elif (techname is None): #return name
        for tech in techlist:
            if tech.ID in techid:
                targettechname.append(tech.name)
                targettechID.append(tech.ID)
    return (targettechname,targettechID)

def readvirusesfile():
    with open('maps/viruses.dat', 'r') as f:
        viruses = f.readlines()[2:]
    viruselist = []
    Viruse = namedtuple("Viruse", ["name", "ID", "cost"])
    for viruse in viruses:
        viruse = viruse.split()
        viruse[4] = viruse[4].split('$')[1]
        viruselist.append(Viruse(viruse[0],viruse[2],float(viruse[4])))
    return viruselist

def getVirusesID(virusesname,virusesid):
    viruselist = readvirusesfile()
    targetviruseID = []
    targetvirusename = []
    if (virusesid is None):  # return IDx
        for viruse in viruselist:
            if viruse.name in virusesname:
                targetviruseID.append(viruse.ID)
                break
    elif (virusesname is None):  # return name
        for viruse in viruselist:
            if viruse.ID in virusesid:
                targetvirusename.append(viruse.name)
                targetviruseID.append(viruse.ID)
    return (targetvirusename,targetviruseID)

def readreportfiles(file):
    with open(file, 'r') as f:
        viruses = f.readlines()
    techID = (viruses[0].split())[2]
    virusedic = {}
    #key: viruse value: units
    for viruse in viruses[4:]:
        viruse = viruse.split()
        if (viruse[1] not in virusedic.keys()):
            virusedic[viruse[1]] = int(viruse[2])
        else:
            virusedic[viruse[1]] += int(viruse[2])
    return (techID,virusedic)

def getTechIDViruses():
    techvirusedic = {}
    for filename in glob.glob(os.path.join('reports/*.dat')):
        techID, virusedic = readreportfiles(filename)
        if (techID not in techvirusedic.keys()):
            techvirusedic[techID] = virusedic
        else:
            for key,value in virusedic.items():
                if key not in techvirusedic[techID].keys():
                    (techvirusedic[techID])[key] = virusedic[key]
                else:
                    (techvirusedic[techID])[key] += virusedic[key]
    return techvirusedic

def getVirusesTechID():
    virusetechdis = {}
    for filename in glob.glob(os.path.join('reports/*.dat')):
        techID, virusedic = readreportfiles(filename)
        for keys,values in virusedic.items():
            if keys not in virusetechdis.keys():
                virusetechdis[keys] = {}
                virusetechdis[keys][techID] = values
            elif techID not in virusetechdis[keys].keys():
                virusetechdis[keys][techID] = values
            else:
                virusetechdis[keys][techID] += values
    return virusetechdis

# # ######################################################
#Task 1
def getTechWork(techName):
    #get target student ID
    _,techID = getTechnicianID(techName,None)
    techID = techID[0]

    #read all reports and find all viruses used by the technician
    techvirusedic = getTechIDViruses()
    #change viruseID to virusename
    try:
        viruseusedbytechID = techvirusedic[techID]
    except:
        return None
    viruseid = list(viruseusedbytechID.keys())
    # get viruses name
    (virusename, viruseID) = getVirusesID(None,viruseid)
    viruseusedbytechname = {}
    for index,name in enumerate(virusename):
        viruseusedbytechname[name] = viruseusedbytechID[viruseID[index]]
    return viruseusedbytechname

#Task 2
def getStrainConsumption(virusName):
    # get target viruses ID
    _,targetviruseID = getVirusesID(virusName,None)
    targetviruseID = targetviruseID[0]
    #read all reports and find all technians used the target viruses
    virusetechdis = getVirusesTechID()
    #change techID to technames
    try:
        viruseusedbytechID = virusetechdis[targetviruseID]
    except:
        return None
    techid = list(viruseusedbytechID.keys())
    (techname,techid) = getTechnicianID(None,techid)
    viruseusedbytechname = {}
    for index,name in enumerate(techname):
        viruseusedbytechname[name] = viruseusedbytechID[techid[index]]
    return viruseusedbytechname

#Task 3
def getTechSpending():
    techlist = readtechniciansfile()
    viruselist = readvirusesfile()
    techvirusedic = getTechIDViruses()

    techspendingdic = {}
    for tech in techlist:
        try:
            virusedic = techvirusedic[tech.ID]
            cost = 0.0
            for viruseID, units in virusedic.items():
                for viruse in viruselist:
                    if viruse.ID == viruseID:
                        cost += units * (viruse.cost)
                        break
            techspendingdic[tech.name] = round(cost,2)
        except:
            pass
    return techspendingdic

#Task 4
def getStrainCost():
    viruselist = readvirusesfile()
    virusetechdic = getVirusesTechID()

    virusespending = {}
    for viruse in viruselist:
        try:
            techdic = virusetechdic[viruse.ID]
            cost = 0.0
            for techID, units in techdic.items():
                cost += units * (viruse.cost)
            virusespending[viruse.name] = round(cost,2)
        except:
            pass
    return virusespending

#Task 5
def getAbsentTechs():
    absenttech = set()
    techlist = readtechniciansfile()
    techvirusedic = getTechIDViruses()
    for tech in techlist:
        try:
            techvirusedic[tech.ID]
        except:
            absenttech.add(tech.name)
    return absenttech

#Task6
def getUnusedStrains():
    absentstrain = set()
    viruselist = readvirusesfile()
    virusetechdic = getVirusesTechID()
    for viruse in viruselist:
        try:
            virusetechdic[viruse.ID]
        except:
            absentstrain.add(viruse.name)
    return absentstrain

# # ######################################################
if __name__  == "__main__":
    #task1
    #task1 = getTechWork('Turner, Theresa')
    #pp(task1)
    #print(type(task1))
 
    #task2
    #task2 = getStrainConsumption('Cardiovirus')
    #pp(task2)
    #print(type(task2))

    #task3
    #task3 = getTechSpending()
    #pp(task3)
    #print(type(task3))

    #task4
    #task4 = getStrainCost()
    #pp(task4)
    #print(type(task4))

    #task5
    #task5 = getAbsentTechs()
    #print(task5,type(task5))

    #task6
    #task6 = getUnusedStrains()
    #print(task6,type(task6))

    pass
