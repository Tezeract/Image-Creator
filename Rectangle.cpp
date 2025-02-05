/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Joel Iacoban
 * joeliaco
 *
 * Reads and writes rectangles for use in pics
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// Default constructor, sets values to 0
Rectangle::Rectangle() {
    start = Point(0,0);
    end = Point(0, 0);
    
    colorTopLeft = Color(0, 0, 0);
    colorTopRight = Color(0, 0, 0);
    colorBottomRight = Color(0, 0, 0);
    colorBottomLeft = Color(0, 0, 0);
}

// Form: R (0,0) (0,0)  0 0 0  0 0 0  0 0 0  0 0 0
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
          Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

void Rectangle::setStart(Point pt) {
    start = pt;
}

Point Rectangle::getStart() {
    return start;
}

void Rectangle::setEnd(Point pt) {
    end = pt;
}

Point Rectangle::getEnd() {
    return end;
}

// Sets same color of all sections of rectangle at one time
void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

void Rectangle::read(istream& ins) {
    char nonInt;
    
    int xValStart;
    int yValStart;
    int xValEnd;
    int yValEnd;
    
    ins >> nonInt;
    ins >> xValStart >> nonInt >> yValStart;
    ins >> nonInt;
    
    start = Point(xValStart, yValStart);
    
    ins >> nonInt;
    ins >> xValEnd >> nonInt >> yValEnd;
    ins >> nonInt;
    
    end = Point(xValEnd, yValEnd);
    
    
    // Seperate RGB values for colors to use in constructor
    int red;
    int green;
    int blue;

    // Read  values for colorTopLeft
    ins >> red >> green >> blue;
    colorTopLeft = Color(red, green, blue);

    // Read  values for colorTopRight
    ins >> red >> green >> blue;
    colorTopRight = Color(red, green, blue);

    // Read values for colorBottomRight
    ins >> red >> green >> blue;
    colorBottomRight = Color(red, green, blue);

    // Read values for colorBottomLeft
    ins >> red >> green >> blue;
    colorBottomLeft = Color(red, green, blue);
    
}

// Rectangle form consists of top left (start) and bottom right (end) points
// Followed by corresponding colors of each corner
// EX: (4,4) (2,6) 40 40 40 30 30 30 255 255 255 0 0 0
void Rectangle::write(ostream& outs) {

    outs << "(" << start.getX() << "," << start.getY() << ") ";
    outs << "(" << end.getX() << "," << end.getY() << ") ";
    
    outs << colorTopLeft << " "  << colorTopRight << " " << colorBottomRight;
    outs << " " << colorBottomLeft;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
