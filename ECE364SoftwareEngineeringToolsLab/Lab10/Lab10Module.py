# ######################################################
#Author :< Yanjun Chen >
#email :< chen2620@purdue.edu >
#ID :< ee364f21 >
#Date :< 11/06/2019 >
# ######################################################

import os
import sys

class TimeSpan:
    def __init__(self, weeks, days, hours):
        if weeks < 0 or days < 0 or hours < 0:
            raise ValueError("The argument cannot be negative.")
        self.hours = hours
        self.weeks = weeks
        self.days = days
        if hours >= 24:
            self.hours = hours % 24
            self.days += hours // 24
        if self.days >= 7:
            self.weeks += self.days // 7
            self.days = self.days % 7

    def __str__(self):
        return f"{format(self.weeks,'02d')}W {format(self.days,'01d')}D {format(self.hours,'02d')}H"

    def getTotalHours(self):
        total = self.weeks * (7 * 24) + self.days * 24 + self.hours
        return total

    def __add__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError ("TimeSpan instance is expected.")
        weeks = self.weeks + other.weeks
        days = self.days + other.days
        hours = self.hours + other.hours
        return TimeSpan(weeks, days, hours)

    def __mul__(self, other):
        if not isinstance(other, int) and not isinstance(other, float):
            raise TypeError ("Unexpected argument type, should be either int or float.")
        if other <= 0:
            raise ValueError("The integer must be greater than 0 (not including 0).")
        hours = round(self.weeks * other * (7 * 24) + self.days * other * 24 + self.hours * other)
        return TimeSpan(0, 0, hours)

    def __rmul__(self, other):
        return (self * other)

    def __lt__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError("Instance must be a TimeSpan class.")
        return self.getTotalHours() < other.getTotalHours()

    def __gt__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError("Instance must be a TimeSpan class.")
        return self.getTotalHours() > other.getTotalHours()

    def __le__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError("Instance must be a TimeSpan class.")
        return self.getTotalHours() <= other.getTotalHours()

    def __ge__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError("Instance must be a TimeSpan class.")
        return self.getTotalHours() >= other.getTotalHours()

    def __eq__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError("Instance must be a TimeSpan class.")
        return self.getTotalHours() == other.getTotalHours()

    def __ne__(self, other):
        if not isinstance(other, TimeSpan):
            raise TypeError("Instance must be a TimeSpan class.")
        return self.getTotalHours() != other.getTotalHours()

if __name__ == "__main__":
    ts1 = TimeSpan(weeks = 2, days = 15, hours = 49)
    ts2 = TimeSpan(weeks = 5, days = 3, hours = 100)
    #print(ts1.weeks, ts1.days, ts1.hours)
    print(ts1)
    print(ts2)
    #print(ts1.getTotalHours())
    #print(ts2.getTotalHours())
    #print(ts1.getTotalHours())
    #print(ts1 + ts2)
    print(ts2 * 2)
    #print(2 * ts1)

    print(ts2 * 0.1)
    #print(2.5 * ts1)
    #print(ts1 < ts2)
    #print(ts1 > ts2)
    #print(ts1 >= ts2)
    #print(ts1 <= ts2)
    #print(ts1 == ts2)
    #print(ts1 != ts2)
    pass