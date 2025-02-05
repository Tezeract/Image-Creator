/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Joel Iacoban
 * joeliaco
 *
 * Sets and gets points based on input from a file or from user
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// Default constructor (0,0)
Point::Point() {
    x = 0;
    y = 0;
}

// Constructor for actual points
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// Range must be [0,99]
// Any values beyond are rounded to 0 or 99 based on proximity
int Point::checkRange(int val) {
    if (val < 0 || val > DIMENSION - 1) {
        if (val < 50) {
            return 0;
        }
        else {
            return DIMENSION - 1;
        }
    }
    return val;
}


void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return x;
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return y;
}

void Point::read(istream &ins) {
    
    // Non integer to take in junk EX: [(4,4): to avoid the parenthees and comma]
    char nonInt;
    
    int xVal;
    int yVal;
    
    // Assigns the integers in corresponding x,y format
    ins >> nonInt;
    ins >> xVal >> nonInt >> yVal;
    ins >> nonInt;
    
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::write(ostream &outs) {
    outs << "(" << x << "," << y << ")";
}



// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
