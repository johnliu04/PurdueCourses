import os
import sys
import math
import copy
import collections
from enum import Enum

class Datum:
    def __init__(self, *args):
        values = []
        for value in args:
            if not isinstance(value, float) and not isinstance(value, int):
                raise TypeError("Not all input arguments are float type.")
            values.append(value)
        self._storage = tuple(values)

    def __str__(self):
        values = format(self._storage[0], '0.2f')
        for value in self._storage[1:]:
            values += ', '
            values += format(value, '0.2f')
        return f"({values})"

    def __repr__(self):
        values = format(self._storage[0], '0.2f')
        for value in self._storage[1:]:
            values += ', '
            values += format(value, '0.2f')
        return f"({values})"

    def __hash__(self):
        return hash(self._storage)

    def distanceFrom(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("The input argument should be Datum Type")
        distance = 0
        selflen = len(self._storage)
        datumlen = len(datum._storage)
        if (selflen > datumlen):
            for index, value in enumerate(datum._storage):
                distance += (value - self._storage[index]) * (value - self._storage[index])
            for value in self._storage[datumlen:]:
                distance += value * value
        elif (selflen < datumlen):
            for index, value in enumerate(self._storage):
                distance += (value - datum._storage[index]) * (value - datum._storage[index])
            for value in datum._storage[selflen:]:
                distance += value * value
        else:
            for index, value in enumerate(self._storage):
                distance += (value - datum._storage[index]) * (value - datum._storage[index])
        return math.sqrt(distance)

    def clone (self):
        newdatum = copy.deepcopy(self)
        return newdatum

    def __contains__(self, item):
        #if not isinstance(item, float) and not isinstance(item, int):
        if type(item) != float and not type(item) != int:
            raise TypeError("Input arguments should be a float type.")
        return item in self._storage

    def __len__(self):
        return len(self._storage)

    def __iter__(self):
        return iter(self._storage)

    def __neg__(self):
        values = []
        for value in self._storage:
            values.append(-abs(value))
        return Datum(*values)

    def __getitem__(self, index):
        return self._storage[index]

    def __add__(self, datum):
        if not isinstance(datum, Datum) and not isinstance(datum, float) and not isinstance(datum, int):
            if not isinstance(datum, Datum):
                raise TypeError("Instance must be a Datum class.")
            if not isinstance(datum, float) and not isinstance(datum, int):
                raise TypeError("Instance must be a float class.")
        values = []
        if isinstance(datum, Datum):
            selflen = len(self._storage)
            datumlen = len(datum._storage)
            if (selflen > datumlen):
                for index, value in enumerate(datum._storage):
                    values.append(self._storage[index] + value)
                for value in self._storage[datumlen:]:
                    values.append(value)
            elif (selflen < datumlen):
                for index, value in enumerate(self._storage):
                    values.append(value + datum._storage[index])
                for value in datum._storage[selflen:]:
                    values.append(value)
            else:
                for index, value in enumerate(self._storage):
                    values.append(value + datum._storage[index])
        if isinstance(datum, float) or isinstance(datum, int):
            for value in self._storage:
                values.append(value + datum)
        return Datum(*values)

    def __radd__(self, datum):
        return (self+datum)

    def __sub__(self, datum):
        if not isinstance(datum, Datum) and not isinstance(datum, float) and not isinstance(datum, int):
            if not isinstance(datum, Datum):
                raise TypeError("Instance must be a Datum class.")
            if not isinstance(datum, float) and not isinstance(datum, int):
                raise TypeError("Instance must be a float class.")
        values = []
        if isinstance(datum, Datum):
            selflen = len(self._storage)
            datumlen = len(datum._storage)
            if (selflen > datumlen):
                for index, value in enumerate(datum._storage):
                    values.append(self._storage[index] - value)
                for value in self._storage[datumlen:]:
                    values.append(value)
            elif (selflen < datumlen):
                for index, value in enumerate(self._storage):
                    values.append(value - datum._storage[index])
                for value in datum._storage[selflen:]:
                    values.append(-value)
            else:
                for index, value in enumerate(self._storage):
                    values.append(value - datum._storage[index])
        if isinstance(datum, float) or isinstance(datum, int):
            for value in self._storage:
                values.append(value - datum)
        return Datum(*values)

    def __mul__(self, datum):
        if not isinstance(datum, float) and not isinstance(datum, int):
            raise TypeError("Instance must be a float class.")
        values = []
        for value in self._storage:
            values.append(value * datum)
        return Datum(*values)

    def __rmul__(self, datum):
        return (self*datum)

    def __truediv__(self, datum):
        if not isinstance(datum, float) and not isinstance(datum, int):
            raise TypeError("Instance must be a float class.")
        values = []
        for value in self._storage:
            values.append(value / datum)
        return Datum(*values)

    def __lt__(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("Instance must be a Datum class.")
        origin = Datum(0)
        return self.distanceFrom(origin) < datum.distanceFrom(origin)

    def __gt__(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("Instance must be a Datum class.")
        origin = Datum(0)
        return self.distanceFrom(origin) > datum.distanceFrom(origin)

    def __le__(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("Instance must be a Datum class.")
        origin = Datum(0)
        return self.distanceFrom(origin) <= datum.distanceFrom(origin)

    def __ge__(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("Instance must be a Datum class.")
        origin = Datum(0)
        return self.distanceFrom(origin) >= datum.distanceFrom(origin)

    def __eq__(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("Instance must be a Datum class.")
        origin = Datum(0)
        return self.distanceFrom(origin) == datum.distanceFrom(origin)

    def __ne__(self, datum):
        if not isinstance(datum, Datum):
            raise TypeError("Instance must be a Datum class.")
        origin = Datum(0)
        return self.distanceFrom(origin) != datum.distanceFrom(origin)

class Data (collections.UserList):
    def __init__(self, args):
        if args is not None:
            for arg in args:
                if not isinstance(arg, Datum):
                    raise TypeError("Each element in the list should be a Datum instance.")
        super().__init__(args)

    def computeBounds(self):
        if self == []:
            return (Datum(0),Datum(0))
        maxnumlist= []
        minnumlist = []
        for value in self[0]:
            maxnumlist.append(value)
            minnumlist.append(value)
        if len(self) == 1:
            return (Datum(*maxnumlist), Datum(*minnumlist))
        #print(maxnumlist,minnumlist)
        for datum in self[1:]:
            for index, value in enumerate(datum):
                try:
                    if maxnumlist[index] < value:
                        maxnumlist[index] = value
                except:
                    if value > 0:
                        maxnumlist.append(value)
                    else:
                        maxnumlist.append(0)
                try:
                    if minnumlist[index] > value:
                        minnumlist[index] = value
                except:
                    if value > 0:
                        minnumlist.append(0)
                    else:
                        minnumlist.append(value)
        #print(maxnumlist, minnumlist)
        return (Datum(*maxnumlist), Datum(*minnumlist))

    def computeMean(self):
        if self == []:
            return Datum(0)
        totallist = []
        averagelist = []
        for value in self[0]:
            totallist.append(value)
        if len(self) == 1:
            return Datum(*totallist)
        for datum in self[1:]:
            for index, value in enumerate(datum):
                try:
                    totallist[index] += value
                except:
                    totallist.append(value)
        for value in totallist:
            averagelist.append(value/(len(self)))
        return Datum(*averagelist)

    def append(self,item):
        if not isinstance(item, Datum):
            raise TypeError("The passed argument is not an instance of the Datum.")
        super().append(item)

    def count(self, item):
        if not isinstance(item, Datum):
            raise TypeError("The passed argument is not an instance of the Datum.")
        return super().count(item)

    def index(self, item, *args):
        if not isinstance(item, Datum):
            raise TypeError("The passed argument is not an instance of the Datum.")
        return super().index(item, *args)

    def insert(self, index, item):
        if not isinstance(item, Datum):
            raise TypeError("The passed argument is not an instance of the Datum.")
        super().insert(index, item)

    def remove(self, item):
        if not isinstance(item, Datum):
            raise TypeError("The passed argument is not an instance of the Datum.")
        super().remove(item)

    def __setitem__(self, key, value):
        if not isinstance(value, Datum):
            raise TypeError("The passed argument is not an instance of the Datum.")
        super().__setitem__(key,value)

    def extend(self, item):
        if not isinstance(item, Data):
            raise TypeError("The passed argument is not an instance of the Data.")
        super().append(item)

class DataClass(Enum):
    Class1 = 1
    Class2 = 2

class DataClassifier:
    def __init__(self, group1, group2):
        if not isinstance(group1, Data) or not isinstance(group2, Data):
            raise TypeError("Two arguments should be Data class.")
        if group1 == [] or group2 == []:
            raise ValueError("Input should not be empty.")
        self._class1 = group1
        self._class2 = group2

    def classify(self, datum):
        if self._class1.computeMean().distanceFrom(datum) <= self._class2.computeMean().distanceFrom(datum):
            return DataClass.Class1
        else:
            return DataClass.Class2

if __name__ == "__main__":
    datum1 = Datum(1.0, 2.0)
    datum2 = Datum(-1.54, 7.10, 9.00, 15.33)
    #print(datum1)
    #print(datum1._storage)
    #print(datum1.distanceFrom(datum2))
    #print(datum1)
    #print(-datum2)
    #print(datum1+datum2)
    #print(datum1-datum2)
    #print(12+datum2)
    #print('s'+datum1)
    #print(datum1*datum2)
    #print(datum1*10)
    #print(10.0*datum1)
    #print(datum1/datum2)
    #print(datum1/10)
    #origin = Datum(0)
    #print(datum1.distanceFrom(origin))
    #print(datum2.distanceFrom(origin))
    #print(datum2!=datum2)

    data1 = Data([datum1, datum2])
    data2 = Data([])
    #data1 = Data([datum1, 12]) #Error
    #data1 = Data(None)
    #print(data1)
    #print(data2.computeBounds())
    #print(data2.computeMean())

    pass