# ######################################################
#Author :< Yanjun Chen >
#email :< chen2620@purdue.edu >
#ID :< ee364f21 >
#Date :< 10/29/2019 >
# ######################################################

import os
import sys
import re
from pprint import pprint as pp

def getNumberPattern():
    pattern = r'([-+]?\d*\.?\d+[eE][-+]?\d*|[-+]?\d*\.?\d+)'
    return pattern

def getLinkPattern():
    pattern = r'href="(?P<url>http://.*?|https://.*?|ftp://.*?|ftps://.*?)">(?P<text>.*?)</a>'
    return pattern

def getDataPattern():
    pattern = r'"(.*?)"[ ]*:[ ]*"(.*?)"'
    return pattern

class Action:
    def __init__(self, actionType, amount):
        if (actionType is not 'W' and actionType is not 'D'):
            raise ValueError("Invalidate action type: should be 'W'(withdraw) or 'D'(deposit)")
        self.actionType = actionType
        self.amount = round(amount, 2)

class Client:
    def __init__(self, firstName, lastName):
        self.firstName = firstName
        self.lastName = lastName

    def __str__(self):
        return f"{self.firstName} {self.lastName}"

class Account:
    def __init__(self, accountNumber, client, amount, minThreshold):
        self.accountNumber = accountNumber
        self.client = client
        self.amount = round(amount, 2)
        self.minThreshold = minThreshold

    def __str__(self):
        if self.amount >= 0:
            return f"{self.accountNumber}, {self.client}, Balance = ${format(self.amount, '0.2f')}"
        else:
            return f"{self.accountNumber}, {self.client}, Balance = (${format(abs(self.amount), '0.2f')})"

    def performAction(self, action):
        if action.actionType == 'D':
            self.amount = round(self.amount+action.amount, 2)
        elif action.actionType == 'W':
            newamount = self.amount-action.amount
            if newamount >= 0:
                if newamount < self.minThreshold:
                    self.amount = round(newamount-10,2)
                else:
                    self.amount = round(newamount,2)
            else:
                raise ValueError("Invalid Action: the amount after the withdraw will not contain a positive amount")

class Institute:
    def __init__(self):
        self.accounts = {}

    def createNew(self, firstname, lastname, accountnum):
        if accountnum in self.accounts.keys():
            return
        client = Client(firstname, lastname)
        self.accounts[accountnum] = Account(accountnum, client, 500.00, 1000.00)

    def performAction(self, accountnum, action):
        try:
            account = self.accounts[accountnum]
            try:
                account.performAction(action)
            except:
                return
            '''
            if action.actionType == 'D':
                account.amount = round(account.amount + action.amount, 2)
            elif action.actionType == 'W':
                newamount = account.amount - action.amount
                if newamount >= 0:
                    if newamount < account.minThreshold:
                        account.amount = round(newamount - 10, 2)
                    else:
                        account.amount = round(newamount, 2)
            '''
        except:
            return

def loadHistory(fileName):
    with open(fileName, 'r') as f:
        fileinfors = f.readlines()[3:]
    institute = Institute()
    for fileinfor in fileinfors:
        clientname = fileinfor.split('"')[1]

        accountnum = fileinfor.split('"')[3]
        institute.createNew(clientname.split()[0], clientname.split()[1], accountnum)

        actioninfo = fileinfor.split('"')[5]
        if actioninfo[0] is '$': ##deposit
            action = Action('D', float(actioninfo[1:]))
        else: ##withdraw
            action = Action('W', float(actioninfo[2:-1]))

        institute.performAction(accountnum, action)

    return institute


if __name__=='__main__':
    #q1
    #pattern = getNumberPattern()
    #s = "With the electron's charge being -1.6022e-19, some choices you have are -110, -32.0 and +55. Assume that pi equals 3.1415, 'e' equals 2.7 and Na is +6.0221E+023 6.3123e023."
    #print(re.findall(pattern, s))

    #q2
    #pattern = getLinkPattern()
    #htmlSnippet = 'You can download the file from <a href="ftps://local.files.io">The Respository</a> or you can search for it <a href="https://www.google.com">here.</a>'
    #m = re.search(pattern, htmlSnippet)
    #print(m['url'])
    #print(m['text'])

    #q3
    #pattern = getDataPattern()
    #s = '{"firstName"  : "George", "lastName" : "Smith", "address":"4546 JINDF., Suit #400", "state" : "New York", "zip" : "20123-345243", "help":}'
    #print(re.findall(pattern, s))

    #q4
    #action1 = Action('W', 12.0432)
    #action2 = Action('D', 1.745)
    #print(action1.amount)

    #q5
    #client1 = Client('John', 'Smith')
    #print(client1)

    #q6
    #account1 = Account('15487-794321', client1, 21985, 12)
    #print(account1)
    #account1.performAction(action1)
    #account1.performAction(action2)
    #print(account1)

    #q7
    #institute1 = Institute()
    #institute1.createNew('John', 'Smith', '15487-794321')
    #institute1.createNew('John', 'Wang', '15483-712343')
    #institute1.performAction('15487-794321', action1)
    #print(institute1)

    #extra credit
    inistitute = loadHistory('history.txt')
    for key,value in inistitute.accounts.items():
        print(value)

    pass