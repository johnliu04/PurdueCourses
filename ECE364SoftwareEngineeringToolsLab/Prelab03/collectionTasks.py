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

#helper function
##read projects.dat
##return two maps: a[projectid] = circuitid
##                 b[circuitid] = projectid
def readprojectid():
    with open('maps/projects.dat', 'r') as f:
        projects = f.readlines()[2:]

    targetcircuitid = {}
    targetprojectid = {}
    for project in projects:
        project = project.split()
        targetcircuitid[project[1]] = []
        targetprojectid[project[0]] = []

    for project in projects:
        project = project.split()
        targetcircuitid[project[1]].append(project[0]) #[projectid] = circuitid
        targetprojectid[project[0]].append(project[1]) #[circuitid] = projectid

    return (targetcircuitid,targetprojectid)

##read student.dat
##return a list with student name and ID
def readstudentid():
    with open('maps/students.dat', 'r') as f:
        students = f.readlines()[2:]
    studentlist = []
    Student = namedtuple("Student",["name","ID"])
    for student in students:
        student = student.split()
        studentlist.append(Student(str(student[0]+' '+student[1]),student[3]))
    return studentlist

##given a circuit ID, form it to a filename format
def helpreadcircuitfiles(circuitid):
    file = 'circuits/circuit_'+circuitid+'.dat'
    return readcircuitfiles(file)

##given a filename of circuit, open the file
##return student ID and component ID
def readcircuitfiles(file):
    with open(file, 'r') as f:
        components = f.readlines()
    index = components.index('Components:\n')+2 #studentid + componentid

    name = []
    for names in components[2:index-3]:
        names = names.split()
        name.append(names[0])
    list = []
    for component in components[index:]:
        component = component.split()
        list.append(component[0])
    return (name,list)

##given a symbol ("R""I""C""T")
##return all the component id and price
def readcomponent(componentSymbol):
    if (componentSymbol == "R"):
        file = 'resistors'  # are identical
    elif (componentSymbol == "I"):
        file = 'inductors'  # are identical
    elif (componentSymbol == "C"):
        file = 'capacitors'  # are identical
    elif (componentSymbol == "T"):
        file = 'transistors'  # are identical
    else:
        ValueError("symbol passed is incorrect")

    with open('maps/'+file+'.dat', 'r') as f:
        components = f.readlines()[3:]

    componentid = {}
    for component in components:
        component = component.split()
        price = component[1].split('$')
        componentid[component[0]] = float(price[1])
    return componentid

##given either student name or student id
##return the student id or student full name
def readstudent(studentName,studentid):
    allstudent = readstudentid()
    if (studentid == None):
        for student in allstudent:
            if student.name == studentName:
                targetstudentid = student.ID
                return targetstudentid
        else:
            raise ValueError("student name passed does not exist")
    elif (studentName == None):
        targetstudent = []
        for student in allstudent:
            if student.ID in studentid:
                targetstudent.append(student.name)
        if (targetstudent == []):
            raise ValueError("student ID passed does not exist")
        return targetstudent

# ######################################################
#Task 10
def getCircuitByComponent(componentIDs):
    circuitid = set()
    for filename in glob.glob(os.path.join('circuits/*.dat')):
        _, components = readcircuitfiles(filename)
        for component in components:
            if component in componentIDs:
                file = filename.split('circuits/circuit_')
                file = (file[1]).split('.dat')[0]  ##circuit ID
                circuitid.add(file)

    return circuitid

#Task 9
def getCircuitByStudent(studentNames):
    circuitid = set()
    studentID = []
    for student in studentNames:
        studentID.append(readstudent(student,None))
    for filename in glob.glob(os.path.join('circuits/*.dat')):
        students, _ = readcircuitfiles(filename)
        for student in students:
            if student in studentID:
                file = filename.split('circuits/circuit_')
                file = (file[1]).split('.dat')[0]  ##circuit ID
                circuitid.add(file)
    return circuitid

#Task8
def getComponentReport(componentIDs):
    map = {}
    ##mapproject = {}
    for componentID in componentIDs:
        map[componentID] = 0
        ##mapproject[componentID] = set()

    _,targetprojectid = readprojectid()
    for filename in glob.glob(os.path.join('circuits/*.dat')):
        _, components = readcircuitfiles(filename)
        for component in components:
            if component in componentIDs:
                file = filename.split('circuits/circuit_')
                file = (file[1]).split('.dat')[0]  ##circuit ID
                #for project in targetprojectid[file]: #find identical project
                    #if project not in mapproject[component]:
                        #mapproject[component].add(project)
                        ##map[component] += 1
                #pp(targetprojectid[file])
                map[component] += len(targetprojectid[file])
    return map

#Task7
def getCommonByProject(projectID1, projectID2):
    targetcircuitid, _ = readprojectid()
    try:
        circuitIDs1 = targetcircuitid[projectID1]
    except:
        raise ValueError("the project ID1 provided does not exists")
    try:
        circuitIDs2 = targetcircuitid[projectID2]
    except:
        raise ValueError("the project ID2 provided does not exists")

    componentlist1 = set()
    componentlist2 = set()
    for circuitID1 in circuitIDs1:
        _, component1 = helpreadcircuitfiles(circuitID1)
        componentlist1.update(component1)
    for circuitID2 in circuitIDs2:
        _, component2 = helpreadcircuitfiles(circuitID2)
        componentlist2.update(component2)

    return sorted(list(componentlist1 & componentlist2))

#Task6
def getProjectByComponent(componentIDs):
    list = []
    for filename in glob.glob(os.path.join('circuits/*.dat')):
        _, components = readcircuitfiles(filename)
        for component in components:
            if component in componentIDs:
                file = filename.split('circuits/circuit_')
                file = (file[1]).split('.dat')[0] ##circuit ID
                list.append(file)

    # read project.dat to find project id
    _, targetprojectid = readprojectid()
    projectid = set()
    for circuitid in list:
        projectid.update(targetprojectid[circuitid])
    return projectid

#Task5
def getCostOfProjects():
    # read project.dat
    targetcircuitid, _ = readprojectid()
    # read symbol.dat
    componentMapR = readcomponent("R")
    componentMapI = readcomponent("I")
    componentMapC = readcomponent("C")
    componentMapT = readcomponent("T")

    map = {}
    totalprice = 0
    for projectID in targetcircuitid.keys():
        circuitid = targetcircuitid[projectID]
        for circuit in circuitid:
            _,components = helpreadcircuitfiles(circuit)
            for component in components:
                if str(component) in componentMapR.keys():
                    totalprice += componentMapR[component]
                elif str(component) in componentMapI.keys():
                    totalprice += componentMapI[component]
                elif str(component) in componentMapC.keys():
                    totalprice += componentMapC[component]
                elif str(component) in componentMapT.keys():
                    totalprice += componentMapT[component]
        map[projectID] = round(totalprice,2)
        totalprice = 0
    return map

#Task4
def getParticipationByProject(projectID):
    # read project.dat
    targetcircuitid, _ = readprojectid()
    try:
        circuitids = targetcircuitid[projectID]
    except:
        raise ValueError("the project ID provided does not exists")

    studentids = []
    # read circuit.dat find which student participated
    for circuitid in circuitids:
        studentid,_ = helpreadcircuitfiles(circuitid)
        studentids += studentid ##stored all studentsID participated in the project

    studentID = readstudent(None,studentids)
    return set(studentID)

#Task3
def getParticipationByStudent(studentName):
    # read student.dat get target student id
    studentid = readstudent(studentName,None)

    # read project.dat to find project id
    _, targetprojectid = readprojectid()
    projectid = set()
    # read all circuit.dat to find which circuit student participate
    for filename in glob.glob(os.path.join('circuits/*.dat')):
        ids, component = readcircuitfiles(filename)
        if studentid in ids:
            file = filename.split('circuits/circuit_')
            file = (file[1]).split('.dat')[0] #get circuit id only
            try:
                projectid.update(targetprojectid[file])
            except:
                print("can not find the projectID with given circuitID")
    return projectid

# Task2
def getComponentCountByStudent(studentName, componentSymbol):
    #read student.dat get target student id
    studentid = readstudent(studentName,None)
    componentdist = set()

    #read all circuit.dat
    componentlist = []
    count = 0
    for filename in glob.glob(os.path.join('circuits/*.dat')):
        ids,component = readcircuitfiles(filename)
        if studentid in ids:
            componentlist += component
    if componentlist == []:
        return 0
    componentMap = readcomponent(componentSymbol)
    for components in componentlist:
        if components in componentMap.keys():
            if components not in componentdist:
                count += 1
                componentdist.add(components)
    return count

#Task1
def getComponentCountByProject(projectID, componentSymbol):
    #read project.dat
    targetcircuitid,_ = readprojectid()
    try:
        circuitids = targetcircuitid[projectID]
    except:
        raise ValueError("the project ID provided does not exists")
    #read symbol.dat
    componentMap = readcomponent(componentSymbol)

    componentdist = set()

    #read components from different circuit.dat
    count = 0
    for circuitid in circuitids:
        _,components = helpreadcircuitfiles(circuitid)
        for component in components:
            if str(component) in componentMap.keys():
                if str(component) not in componentdist:
                    count += 1
                    componentdist.add(str(component))
    return count

# # ######################################################
if __name__  == "__main__":
    #task1
    #print(getComponentCountByProject("082D6241-40EE-432E-A635-65EA8AA374B61", "R"))

    #task2
    #studentlist = readstudentid()
    #for student in studentlist:
    #    print('student is '+ student.name, getComponentCountByStudent(student.name,"R"))
    #print(getComponentCountByStudent("Adams, Keit","R"))

    #task3
    #print(getParticipationByStudent("Adams, Keit"))

    #task4
    #print(getParticipationByProject('082D6241-40EE-432E-A635-65EA8AA374B61'))

    #task5
    #print(getCostOfProjects())

    #task6
    #print(getProjectByComponent({'RNW-02','HRK-348','KSR-430'}))

    #task7
    #print(getCommonByProject("56B13184-D087-48DB-9CBA-84B40FE17CC5", "0F1FABFA-E112-4A66-A0B0-B7A2C14AD39A1"))

    #task8
    #print(getComponentReport({'RTD-159', 'MGC-590', 'OLW-497', 'SLT-436', 'TMS-946'}))
    #print(getComponentReport({'MGC-59'}))

    #task9
    #print(getCircuitByStudent({"Adams, Keit","Alexander, Carlos","Allen, Amanda"}))

    #task10
    print(getCircuitByComponent({'SLT-436'}))
    pass
