/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Joel Iacoban
 * joeliaco
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Line();
    test_Circle();
    test_Rectangle();
    test_Triangle();
    
    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    return;
}

void test_Color() {
    // test of default constructor
    Color c1;
    cout << "Expected: 0 0 0 actual: " << c1 << endl;
    
    // test of the non-default constructor
    Color c2(4, 32, 2);
    cout << "Expected: 4 32 2 , actual: " << c2 << endl << endl;

    // test of member function: setRed()
    c1.setRed(5);
    // test of member function: setGreen()
    c1.setGreen(3);
    // test of member function: setBlue()
    c1.setBlue(7);
    

    // test of member functions getRed() and getGreen() and getBlue()
    cout << "Expected: 5 3 7 , actual: ";
    cout << c1.getRed() << " " << c1.getGreen() << " " << c1.getBlue();
    cout << endl << endl;
    
    c1.setBlue(40);
    cout << "Expected: 40, Actual: " << c1.getBlue() << endl << endl;
    
    Color c3(-100, 400, 256);
    cout << "Expedcted: 0 255 255, Actual: " << c3 << endl << endl;
    
    return;
}

void test_Line() {
    Line L1;
    cout << "Expected: L (0,0) (0,0) 0 0 0, Actual: " << L1 << endl << endl;
    
    Line L2;
    Point pt1 = Point(4,4);
    Point pt2  = Point(7,7);
    Color c1 = Color(44, 458, 200);
    L2 = Line(pt1, pt2, c1);
    
    cout << "Expected: L (4,4) (7,7) 44 455 200, Actual: " << L2 << endl;
    
    Line L3;
    Line L4;
    
    L3.setStart(pt1);
    L3.setEnd(pt2);
    
    L4.setStart(pt1);
    L4.setEnd(pt2);
    
    cout << "Expected: (4,4) (7,7), Actual: " << L3.getStart() << " "
    << L3.getEnd() << endl;
    
    ofstream testFile("data1.txt");
    L3.write(testFile);
    testFile.close();
    
    ifstream testFile2("data2.txt");
    L4.read(testFile2);
    cout << L4 << endl;
    testFile2.close();
    
}

void test_Circle() {
    Circle circ1;
    cout << "Expected: C (0,0)  0  0 0 0, Actual: " << circ1 << endl << endl;
    
    Circle circ2;
    Point pt1 = Point(4,4);
    Color c1 = Color(40, 40, 40);
    
    circ2 = Circle(pt1, -1, c1);
    cout << "Expected: C (4,4)  1  40 40 40, Actual: " << circ2 << endl << endl;
    
    circ2.setCenter(pt1);
    
    cout << circ2.getCenter() << endl;
    
    circ2.setRadius(-40);
    cout << circ2.getRadius() << endl;
    
    Circle C3;
    Circle C4;
    
    C3.setCenter(pt1);
    C3.setRadius(-3);
    
    C4.setCenter(pt1);
    C4.setRadius(-3);
    
    ofstream testFile("data1.txt");
    C3.write(testFile);
    testFile.close();
    
    ifstream testFile2("data2.txt");
    C4.read(testFile2);
    cout << C4 << endl;
    testFile2.close();
    
    
}

void test_Rectangle() {
    Rectangle r1;
    cout << "Expected: R (0,0)  (0,0) 0 0 0 0 0 0 0 0 0 0 0 0, Actual: ";
    cout << r1 << endl << endl;
    
    Point start1 = Point(4,4);
    Point end1 = Point(7, 1);
    
    Color color1 = Color(40, 40, 40);
    r1 = Rectangle(start1, end1, color1, color1, color1, color1);
    cout << r1 << endl << endl;
    
    cout << r1.getEnd() << endl << endl;
    
    r1.setColor(color1);
    cout << r1.getColorTopLeft() << " " << r1.getColorTopRight() << " "
    << r1.getColorBottomRight() << " " << r1.getColorBottomLeft() << endl;
    
    r1.setStart(start1);
    cout << r1.getStart() << endl;
}

void test_Triangle() {
    Triangle t1;
    cout << "Expected: T (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0, Actual: "
    << t1 << endl << endl;
    
    Point v1 = Point(4, 4);
    Point v2 = Point(2, 2);
    Point v3 = Point(6, 2);
    
    Color cv1 = Color(40, 40, 40);
    Color cv2 = Color(40, 40, 40);
    Color cv3 = Color(40, 40, 40);
    
    t1 = Triangle(v1, cv1, v2, cv2, v3, cv3);
    cout << t1 << endl << endl;
    
    cout << t1.getVertexOne() << endl;
    cout << t1.getVertexOneColor() << endl;
    
    ofstream testFile("data1.txt");
    t1.write(testFile);
    
    
    
}

  
    
