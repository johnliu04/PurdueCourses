#!/usr/local/bin/python3.7

# ######################################################
# Author : < Yanjun Chen >
# email : < chen2620 >
# ID : < ee364f21 >
# Date : < 9/11/2019 >
# ######################################################

import os # List of module import statements
import sys # Each one on a line
import glob
from pprint import pprint as pp

def getMonthlyVolume():
    with open('stocks.dat', 'r') as f:
        stock = f.readlines()[2:]

    dictionary = {}
    for allinfor in stock:
        allinfor = allinfor.split(',')
        date = allinfor[0].split('/')
        dictionary[date[0]+'/'+date[1]] = 0

    for allinfor in stock:
        allinfor = allinfor.split(',')
        date = allinfor[0].split('/')
        dictionary[date[0]+'/'+date[1]] += int(float(allinfor[2]))
    return dictionary

def getCommonDays(year1, year2):
    with open('stocks.dat', 'r') as f:
        stock = f.readlines()[2:]

    dictionary = {}
    dictionary[year1] = []
    dictionary[year2] = []
    for allinfor in stock:
        allinfor = allinfor.split(',')
        date = allinfor[0].split('/')
        if (date[0] == year1):
            dictionary[year1].append((date[1],date[2]))
        elif (date[0] == year2):
            dictionary[year2].append((date[1],date[2]))

    commondate = set()
    for month,date in dictionary[year1]:
        if ((month,date) in dictionary[year2]):
            commondate.add((month,date))
    return commondate

def getNamesBySymbol(n):
    with open('transactions.dat', 'r') as f:
        transactions = f.readlines()

    dictionary = {}
    for transaction in transactions:
        transaction = transaction.split(': ')
        companys = transaction[1].split('\n')
        companys = companys[0].split(', ')
        for company in companys:
            dictionary[company] = set()

    for transaction in transactions:
        transaction = transaction.split(': ')
        companys = transaction[1].split('\n')
        companys = companys[0].split(', ')
        for company in companys:
            if (companys.count(company) >= n):
                dictionary[company].add(transaction[0])

    return dictionary

# # ######################################################
if __name__  == "__main__":
    #problem 1
    #pp(getMonthlyVolume())

    #problem 2
    #setvalue = getCommonDays("2018","2017")
    #pp(setvalue)
    #print(len(setvalue))

    #bouns
    #pp(getNamesBySymbol(1))
    pass