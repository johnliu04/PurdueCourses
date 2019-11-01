# ######################################################
#Author :< Yanjun Chen >
#email :< chen2620@purdue.edu >
#ID :< ee364f21 >
#Date :< 10/03/2019 >
# ######################################################

import os
import sys
from enum import Enum

class Level(Enum):
    Freshman = 9
    Sophomore = 10
    Junior = 11
    Senior = 12

class ComponentType(Enum):
    Resistor = 1
    Capacitor = 2
    Inductor = 3
    Transistor = 4

class Student:
    def __init__(self, ID, firstName, lastName, level):
        self.ID = ID
        self.firstName = firstName
        self.lastName = lastName
        if level not in Level:
            raise TypeError("The argument must be an instance of the 'Level' Enum.")
        self.level = level

    def __str__(self):
        return (f"{self.ID}, {self.firstName} {self.lastName}, "
                f"{(self.level).name}")

class Component:
    def __init__(self, ID, ctype, price):
        self.ID = ID
        if ctype not in ComponentType:
            raise TypeError("The argument must be an instance of the 'ComponentType' Enum.")
        self.ctype = ctype
        self.price = price

    def __str__(self):
        return (f"{self.ctype.name}, {self.ID}, ${format(self.price,'0.2f')}")

    def __hash__(self):
        return hash(self.ID)

class Circuit:
    def __init__(self, ID, components):
        self.ID = ID
        cost = 0
        for component in components:
            if not isinstance(component, Component):
                raise TypeError("The argument must be an instance of the 'Component' class.")
            cost += component.price
        self.components = components
        self.cost = cost

    def __str__(self):
        r = len(self.getByType(ComponentType.Resistor))
        c = len(self.getByType(ComponentType.Capacitor))
        i = len(self.getByType(ComponentType.Inductor))
        t = len(self.getByType(ComponentType.Transistor))
        return (f"{self.ID}: (R = {format(r,'02d')}, C = {format(c,'02d')}, "
                f"I = {format(i,'02d')}, T = {format(t,'02d')})"
                f", Cost = ${format(self.cost,'0.2f')}")

    def getByType(self, componentype):
        if not isinstance(componentype, ComponentType):
            raise ValueError("The argument must be an instance of the 'ComponentType' class.")
        result = set()
        for component in self.components:
            if component.ctype == componentype:
                result.add(component)
        return result

    def __contains__(self, component):
        if not isinstance(component, Component):
            raise TypeError("The argument must be an instance of the 'Component' class.")
        if component in self.components:
            return True
        return False

    def __add__(self, component):
        if not isinstance(component, Component):
            raise TypeError("The argument must be an instance of the 'Component' class.")
        if component in self.components:
            return self
        self.components.add(component)
        self.cost += component.price
        return self

    def __radd__(self, component):
        return (self+component)

    def __sub__(self, component):
        if not isinstance(component, Component):
            raise TypeError("The argument must be an instance of the 'Component' class.")
        if component not in self.components:
            return self
        self.components.remove(component)
        self.cost -= component.price
        return self

    def __eq__(self, circuit2):
        if not isinstance(circuit2, Circuit):
            raise TypeError("The argument must be an instance of the 'Circuit' class.")
        return (self.cost == circuit2.cost)

    def __lt__(self, circuit2):
        if not isinstance(circuit2, Circuit):
            raise TypeError("The argument must be an instance of the 'Circuit' class.")
        return (self.cost < circuit2.cost)

    def __gt__(self, circuit2):
        if not isinstance(circuit2, Circuit):
            raise TypeError("The argument must be an instance of the 'Circuit' class.")
        return (self.cost > circuit2.cost)

class Project:
    def __init__(self, ID, participants, circuits):
        self.ID = ID
        for participant in participants:
            if not isinstance(participant, Student):
                raise ValueError("The argument must be an instance of the 'Student' class.")
        self.participants = participants
        cost = 0
        for circuit in circuits:
            if not isinstance(circuit, Circuit):
                raise ValueError("The argument must be an instance of the 'Circuit' class.")
            cost += circuit.cost
        self.circuits = circuits
        self.cost = cost

    def __str__(self):
        return (f"{self.ID}: ({format(len(self.circuits),'02d')} Circuist, "
                f"{format(len(self.participants),'02d')} Participants), "
                f"Cost = ${format(self.cost,'0.2f')}")

    def __contains__(self, target):
        if isinstance(target, Component):
            for circuit in self.circuits:
                for comp in circuit.components:
                    if comp == target:
                        return True
            return False
        elif isinstance(target,Circuit):
            for circuit in self.circuits:
                if circuit == target:
                    return True
            return False
        elif isinstance(target,Student):
            for participant in self.participants:
                if participant == target:
                    return True
            return False
        raise TypeError("The argument must be an instance of the a certain class.")

    def __add__(self, circuit):
        if not isinstance(circuit, Circuit):
            raise TypeError("The argument must be an instance of the 'Component' class.")
        if circuit in self.circuits:
            return self
        self.circuits.add(circuit)
        self.cost += circuit.cost
        return self

    def __sub__(self, circuit):
        if not isinstance(circuit, Circuit):
            raise TypeError("The argument must be an instance of the 'Component' class.")
        if circuit not in self.circuits:
            return self
        self.circuits.remove(circuit)
        self.cost -= circuit.cost
        return self

    def __getitem__(self, circuitID):
        for circuit in self.circuits:
            if (circuitID == circuit.ID):
                return circuit
        raise KeyError("The argument 'circuit' is not presented in the project.")

class Capstone (Project):
    def __init__(self, kwargs):
        if 'participants' in kwargs.keys():
            participants = kwargs['participants']
        elif 'project' in kwargs.keys():
            participants = kwargs['project'].participants
        else:
            raise ValueError("Unable to instantiate the class and populat the member variables.")
        for participant in participants:
            if participant.level is not Level.Senior:
                raise ValueError("Not all participating students are seniors.")

if __name__ == "__main__":
    student = Student("15487-79431","John","Smith",Level.Freshman)
    #student = Student("15487-79431","John","Smith",Level.Frehman)
    #student = Student("15487-79431","John","Smith","Freshman")
    print(student)
    print()

    student2 = Student("15487-73401","John","Smith",Level.Senior)
    student3 = Student("15487-79821","John","Smith",Level.Senior)
    student4 = Student("15487-79231","John","Smith",Level.Senior)
    student5 = Student("15487-79331","John","Smith",Level.Senior)


    component1 = Component("REW-321", ComponentType.Resistor, 1.40)
    component2 = Component("CEW-321", ComponentType.Capacitor, 1.50)
    component3 = Component("IEW-321", ComponentType.Inductor, 3.40)
    component4 = Component("TEW-321", ComponentType.Transistor, 4.50)
    component5 = Component("REW-111", ComponentType.Resistor, 1.67)
    component6 = Component("IEW-10", ComponentType.Inductor, 4.00)
    component7 = Component("CEW-10", ComponentType.Capacitor, 3.00)
    print(component1, component2, component3, component4, component5, component6)
    print()

    circuit = Circuit("ID1", {component1, component2, component3, component4, component5, component6})
    print(circuit)
    print()

    print(component7 in circuit)

    #print(circuit+component7)
    print(component7+circuit)
    #print(student+circuit)
    print(circuit - component7)
    print(circuit - component7)

    circuit2 = Circuit("ID2", {component1, component2, component3, component4, component5, component6, component7})
    print(circuit2)

    print(circuit<circuit2)

    project = Project('ID', [student], [circuit,circuit2])
    print(project)

    component8 = Component("REW-122", ComponentType.Resistor, 2.00)
    print(component1 in project)

    print(project + circuit)
    print(project - circuit)

    print(project['ID2'])

    dic = {}
    dic['ID'] = '12321'
    dic['participants'] = [student2,student3,student4,student5]
    cap = Capstone(dic)