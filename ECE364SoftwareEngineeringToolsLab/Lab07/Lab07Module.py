# ######################################################
#Author :< Yanjun Chen >
#email :< chen2620@purdue.edu >
#ID :< ee364f21 >
#Date :< 10/03/2019 >
# ######################################################

import os
import sys

class Rectangle:
    def __init__(self, llPoint, urPoint):
        if llPoint[0] < urPoint[0] and llPoint[1] < urPoint[1]:
            self.lowerLeft = llPoint
            self.upperRight = urPoint
        else:
            raise ValueError("Lower-left point's coordinates are not lower than those of upper-right point.")

    def isSquare(self):
        #define if the current rectangle is a square
        (xll, yll) = self.lowerLeft
        (xur, yur) = self.upperRight
        if (xur - xll) == (yur - yll):
            return True
        return False

    def intersectsWith(self, rect):
        ##rect four corner inside the self rectangle
        if not isinstance(rect, Rectangle):
            return
        (xll, yll) = self.lowerLeft
        (xur, yur) = self.upperRight
        (rxll, ryll) = rect.lowerLeft
        (rxur, ryur) = rect.upperRight
        (rxul, ryul) = (rxll, ryur)
        (rxlr, rylr) = (rxur, ryll)

        if xll < rxll < xur and yll < ryll < yur:
            return True
        if xll < rxur < xur and yll < ryur < yur:
            return True
        if xll < rxul < xur and yll < ryul < yur:
            return True
        if xll < rxlr < xur and yll < rylr < yur:
            return True
        return False

    def __eq__(self, Rectangle2):
        if not isinstance(Rectangle2, Rectangle):
            raise TypeError("Input Rectangle2 is not an instance of the Rectangle class.")
        (xll, yll) = self.lowerLeft
        (xur, yur) = self.upperRight
        (xll2, yll2) = Rectangle2.lowerLeft
        (xur2, yur2) = Rectangle2.upperRight

        area1 = (xur - xll) * (yur - yll) #area of self
        area2 = (xur2 - xll2) * (yur2 - yll2) #area of rectangle2

        if round(area1, 4) == round(area2, 4):
            return True
        return False

class Circle:
    def __init__(self, center, radius):
        if radius > 0:
            self.radius = radius
            self.center = center
        else:
            raise ValueError ("Radius for the circle should greater than 0.")

    def intersectsWith(self, other):
        if isinstance(other, Circle):
            (x1, y1) = self.center
            r1 = self.radius
            (x2, y2) = other.center
            r2 = other.radius
            if (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 + r2) * (r1 + r2):
                return True
            return False
        elif isinstance(other, Rectangle):
            (x1, y1) = self.center
            r1 = self.radius
            (xll, yll) = other.lowerLeft
            (xur, yur) = other.upperRight
            (xul, yul) = (xll, yur)
            (xlr, ylr) = (xur, yll)
            if (xll - x1) * (xll - x1) + (yll - y1) * (yll - y1) < (r1 * r1):
                return True
            if (xur - x1) * (xur - x1) + (yur - y1) * (yur - y1) < (r1 * r1):
                return True
            if (xul - x1) * (xul - x1) + (yul - y1) * (yul - y1) < (r1 * r1):
                return True
            if (xlr - x1) * (xlr - x1) + (ylr - y1) * (ylr - y1) < (r1 * r1):
                return True
            return False
        else:
            return None


if __name__=='__main__':
    rec1 = Rectangle((-1.23, -0.12), (2.34, 3.23))
    rec2 = Rectangle((-1.0, -1.0), (0.0, 0.0))
    rec3 = Rectangle((0.77, 2.88), (4.34, 6.23))
    print(rec1.isSquare())
    print(rec2.isSquare())

    print(rec1.intersectsWith(rec3))
    print(rec3.intersectsWith(rec1))
    print(rec1 == rec3)

    print("\nextra credit")
    cir1 = Circle((0.0, 0.0), 2.0)
    cir2 = Circle((3.0, 0.0), 5.0)

    print(cir1.intersectsWith(rec1))
    print(cir2.intersectsWith(cir1))
    print(cir1.intersectsWith(cir2))

