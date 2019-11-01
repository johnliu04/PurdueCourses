#!/usr/local/bin/python3.7

# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620 >
# ID : < ee364f21 >
# Date : < 9/25/2019 >
# ######################################################

import os # List of module import statements
import sys # Each one on a line
import re
from uuid import UUID
from pprint import pprint as pp

def getUrlParts(url):
    pattern = r'http://(?P<BaseAddress>[\w.-]*)/(?P<Controller>[\w.-]*)/(?P<Action>[\w.-]*).?(?P<QueryString>(.*$))'
    result = re.search(pattern,url)
    ##print(result.groupdict())
    return (result["BaseAddress"],result["Controller"],result["Action"])

def getQueryParameters(url):
    pattern = r'http://(?P<BaseAddress>[\w.-]*)/(?P<Controller>[\w.-]*)/(?P<Action>[\w.-]*).?(?P<QueryString>(.*$))'
    querystring = re.search(pattern,url)["QueryString"]
    pattern = r'([\w.-]*)=([\w.-]*)'
    result = re.findall(pattern,querystring)
    return result

def getSpecial(sentence, letter):
    pattern = r'\b'+letter+'\w*'+r'[^'+letter+'\W]'+r'\b'
    pattern = pattern +'|'+r'\b'+'[^'+letter+'\W]\w*'+letter+r'\b'
    result = re.findall(pattern, sentence, re.IGNORECASE)
    return result

def getRealMAC(sentence):
    pattern = r'[^-:0-9a-f](([0-9a-f]{2}[-:]){5}[0-9a-f]{2})[^-:0-9a-f]'
    result = re.search(pattern,sentence,re.IGNORECASE)
    try:
        result = result[1]
    except:
        pattern = r'^(([0-9a-f]{2}[-:]){5}[0-9a-f]{2})[^-:0-9a-f]' #begining
        result = re.search(pattern,sentence,re.IGNORECASE)
        try:
            result = result[1]
        except:
            pattern = r'[^-:0-9a-f](([0-9a-f]{2}[-:]){5}[0-9a-f]{2})$' #ending
            result = re.search(pattern, sentence, re.IGNORECASE)
            try:
                result = result[1]
            except:
                result = None
    return result

def readEmployees():
    employeedic = {}
    namepattern = r'(^([a-z]*)(, | )([a-z]*)\b)'
    IDpattern = r'(\b\w{8}(|-)\w{4}(|-)\w{4}(|-)\w{4}(|-)\w{12}\b)'
    phonepattern = r'(\b(\d{3})(|\) |-)(\d{3})(|-)(\d{4})\b)'
    statepattern = r'(\b([a-z]* |)[a-z]*$)'

    with open('Employees.dat', 'r') as f:
        employees = f.readlines()
    for employee in employees:
        name = re.search(namepattern,employee,re.IGNORECASE)
        if name.group(3) == ', ':
            name = name.group(4)+' '+name.group(2)
        else:
            name = name.group(1)
        employeedic[name] = {}

        ID = re.search(IDpattern,employee,re.IGNORECASE)
        if ID is not None:
            ID = str(UUID(ID[1]))
            employeedic[name]['ID'] = ID
        phone = re.search(phonepattern,employee,re.IGNORECASE)
        if phone is not None:
            if (phone.group(3) == ') '):
                phone = '('+phone.group(1)
            else:
                phone = '('+phone.group(2)+') '+phone.group(4)+'-'+phone.group(6)
            employeedic[name]['phone'] = phone
        state = re.search(statepattern,employee,re.IGNORECASE)
        if state is not None:
            state = state[1]
            employeedic[name]['state'] = state

    return employeedic

def getRejectedEntries():
    employeedic = readEmployees()
    list = []
    for key,value in employeedic.items():
        if value == {}:
            list.append(key)
    return sorted(list)

def getEmployeesWithIDs():
    employeedic = readEmployees()
    result = {}
    for key,value in employeedic.items():
        try:
            id = value['ID']
            result[key] = id
        except:
            pass
    return result

def getEmployeesWithoutIDs():
    employeedic = readEmployees()
    result = []
    for key,value in employeedic.items():
        if bool(value) :
            try:
                value['ID']
            except:
                result.append(key)
    return sorted(result)

def getEmployeesWithPhones():
    employeedic = readEmployees()
    result = {}
    for key, value in employeedic.items():
        try:
            phone = value['phone']
            result[key] = phone
        except:
            pass
    return result

def getEmployeesWithStates():
    employeedic = readEmployees()
    result = {}
    for key, value in employeedic.items():
        try:
            state = value['state']
            result[key] = state
        except:
            pass
    return result

def getCompleteEntries():
    employeedic = readEmployees()
    result = {}
    for key, value in employeedic.items():
        if len(value.keys()) == 3:
            ID = value['ID']
            phone = value['phone']
            state = value['state']
            result[key] = (ID, phone, state)
    return result

# # ######################################################
if __name__  == "__main__":
    #q1 = getUrlParts("http://w/Home/Calendar?Year=2016&Month=September&Semester=Fall")
    #print(q1)

    #q2 = getQueryParameters("http://www.google.com/Math/Const?Pi=3.14&Max_Int=65536&What_Else=Not-Here")
    #print(q2)

    #q3 = getSpecial("The TART program runs on Tuesdays and Thursdays, but it does not start until next week.", "t")
    #print(q3)

    q4 = getRealMAC("58:1C-0A-6E-39-4D, The TART program runs on , but it does not start until next week ")
    #q4 = getRealMAC("The TART program runs on, but it does not start until next week.")
    print(q4)

    #q5 = getRejectedEntries()
    #print(q5)

    #q6 = getEmployeesWithIDs()
    #pp(q6)

    #q7 = getEmployeesWithoutIDs()
    #pp(q7)

    #q8 = getEmployeesWithPhones()
    #pp(q8)

    #q9 = getEmployeesWithStates()
    #pp(q9)

    #q10 = getCompleteEntries()
    #pp(q10)
    pass