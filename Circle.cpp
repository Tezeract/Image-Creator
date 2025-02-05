/**
 * Circle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Joel Iacoban
 * joeliaco
 *
 * Reads and writes circles of form center, radius, and color
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;

// Default constructor
Circle::Circle() {
    center = Point(0,0);
    radius = 0;
    color = Color(0, 0, 0);
}

// Constructs circle of form center radius color [(0,0) 1 100 100 100]
Circle::Circle(Point pt, int r, Color c) {
    center = pt;
    radius = checkRadius(r);
    color = c;
}

// Form: (0,0)
void Circle::setCenter(Point pt) {
    center = pt;
}

Point Circle::getCenter() {
    return center;
}

// Radius must be positive
void Circle::setRadius(int r) {
    radius = checkRadius(r);
}

int Circle::getRadius() {
    return radius;
}

// Form: 0 0 0, range: 0 to 255
void Circle::setColor(Color c) {
    color = c;
}

Color Circle::getColor() {
    return color;
}

void Circle::read(istream &ins) {
    
    // For non ( and , and ) in a point; makes it junk
    char nonInt;
    
    // Values for center to use for constructing
    int xVal;
    int yVal;
    
    // Insertion values for color to use for constructing
    int redVal;
    int greenVal;
    int blueVal;
    
    // Assigns the integers in corresponding x,y format for center
    ins >> nonInt;
    ins >> xVal >> nonInt >> yVal;
    ins >> nonInt;
    
    // Uses point non-default constructor and assigns to center
    center = Point(xVal, yVal);
    
    // Getsr radius and gets absolute value of it
    ins >> radius;
    radius = checkRadius(radius);
    
    // Reads in colors in form 0 0 0, then uses non-default constructor
    ins >> redVal >> greenVal >> blueVal;
    color = Color(redVal, greenVal, blueVal);
}

void Circle::write(ostream &outs) {
    
    // Calls get functions of Point, since x and y are private members of Point
    outs << "(" << center.getX() << "," << center.getY() << ") ";
    outs << radius << " ";
    outs << color;
}



// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
