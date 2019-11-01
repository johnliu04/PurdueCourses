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
def readAllProvidersFile():
    dict = {}
    for filename in glob.glob(os.path.join('providers/*.dat')):
        filename = filename.split("providers/")
        filename = filename[1].split(".dat")
        dict[filename[0]] = []
        name, price = readProvidersFile(filename[0])
        dict[filename[0]].append(name)
        dict[filename[0]].append(price)
    return dict

def readProvidersFile(filename):
    try:
        with open('providers/'+filename+'.dat', 'r') as f:
            SBCs = f.readlines()[3:]
    except:
        raise ValueError("Providers does not exist in the folder")
    namelist = []
    pricelist = []
    for SBC in SBCs:
        SBC = SBC.split()
        namelist.append(SBC[0]+' '+SBC[1])
        price = SBC[3].split('$')
        pricelist.append(float(price[1]))
    return (namelist,pricelist)

#Task1
def getDifference(provider1, provider2):
    name1,_ = readProvidersFile(provider1)
    name2,_ = readProvidersFile(provider2)

    for name in name2:
        try:
            name1.remove(name)
        except:
            pass
    return set(name1)

#Task2
def getPriceOf(sbc,provider):
    name, price = readProvidersFile(provider)
    if sbc in name:
        i = name.index(sbc)
        sbcprice = price[i]
    else:
        raise ValueError("The provider does not carry the SBC requested")
    return sbcprice

#Task3
def checkAllPrices(sbcSet):
    dic = readAllProvidersFile()
    minidic = {}
    for sbc in sbcSet:
        miniprice = '1'
        minituple = (0, 0)
        for provider,value in dic.items():
            if sbc in value[0]:
                i = value[0].index(sbc)
                sbcprice = value[1][i]
                if miniprice == '1' or miniprice > sbcprice:
                    miniprice = sbcprice
                    minituple = (sbcprice,provider)
        if minituple is not (0,0):
            minidic[sbc] = minituple
    return minidic

#Extra Credit
def getFilter():
    dict = {}
    #generate 3-digit strings
    for i in range(10):
        for j in range(10):
            for k in range(10):
                dict[str(i)+str(j)+str(k)] = set()
    with open('phones.dat', 'r') as f:
        phones = f.readlines()[1:]
    for phone in phones:
        phone = phone.split(',')
        phone = phone[1]
        phone = phone.strip()
        phonenumber = phone.split('(')[1]
        phonenumber = phonenumber.split(') ')
        phonenumber = phonenumber[0]+phonenumber[1]
        phonenumber = phonenumber.split('-')
        phonenumber = phonenumber[0]+phonenumber[1]
        for index,value in enumerate(phonenumber[0:-2]):
            dict[phonenumber[index:index+3]].add(phone)
    phonedic = {}
    for key,values in dict.items():
        if len(values) == 1:
            phonedic[key] = values
    return phonedic

# # ######################################################
if __name__  == "__main__":
    #task1
    #print(getDifference("provider2","provider4"))

    #task2
    #print(getPriceOf("Rasp. Pi-4702MQ","provider2"))

    #task3
    #print(checkAllPrices({"Rasp. Pi-4702MQ","Rasp. Pi-6650U"}))

    #extra credit
    pp(getFilter())
    pass