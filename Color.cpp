/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Joel Iacoban
 * joeliaco
 *
 * Creates or recieves a color of form 0 0 0 using the RGB range from 0-255
 */

#include "Color.h"

// Range must be between 0 and 255, which is the RGB spectrum
// Any values beyond are rounded to 0 or 255 based on proximity
int Color::checkRange(int val) {
    if (val < 0) {
        return 0;
    }
    else if (val > 255) {
        return 255;
    }
    else {
        return val;
    }
}
// Default constructor, sets color to black (0, 0, 0)
Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

// Parameter based constructor; sets color values
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

void Color::setRed(int redVal) {
    redVal = checkRange(redVal);
    red = redVal;
}

int Color::getRed() {
    return red;
}

void Color::setGreen(int greenVal) {
    greenVal = checkRange(greenVal);
    green = greenVal;
}

int Color::getGreen()  {
    return green;
}

void Color::setBlue(int blueVal) {
    blueVal = checkRange(blueVal);
    blue = blueVal;
}

int Color::getBlue() {
    return blue;
}

// Reads in color values in form red green blue EX: (0 0 0)
void Color::read(istream& ins) {
    // Storage of the values for range checking
    int redVal;
    int greenVal;
    int blueVal;
    
    // Inputs in format 0 0 0
    ins >> redVal >> greenVal >> blueVal;
    
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

// Writes out in form red green blue EX: (0 0 0)
void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
