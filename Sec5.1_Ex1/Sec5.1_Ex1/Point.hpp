//  Point.hpp

//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Point class with cartesian coordiantes. Functionalities include returning and setting (x,y) points, a string function that returns text description of the point and distance functions to calculate distance between 2 points.
// Added operators to perform various functions like addition, negation, multiplications and assignments and printing with cout.

#ifndef __Sec3_4_Ex2__Point__
#define __Sec3_4_Ex2__Point__

#include <iostream>
#include<string>
#include"Shape.hpp"
using namespace std;
namespace Anees{namespace CAD{
    
class Point:public Shape
{
private:
    double m_x;   //x coordinate
    double m_y;   //y coordinate
    
public:
    //constructors and destructors
    Point();    //constructor
    Point (double x, double y); // constructor
    Point (const Point&Pt); // copy constructor
    ~Point();   //destructor
    
    //Accessing functions
    double X() const;  //Get X coordinate
    double Y() const;  //Get Y coordinate
    void X(double x); // set X coordinate
    void Y(double y);// set Y coordinate
    string ToString() const; //Returns string description of Point
    
    //functionality
    double Distance() const;                //Calculate distance from origin
    double Distance(const Point& Pt) const; // Calculate distance between two points, passing Point
    //object by reference
    void Draw() const;      // Base class method overridden by point class method
    
    //operators
    Point operator - () const; // Negate coordinates
    Point operator * (double factor) const; //scale coordinates by a factor
    Point operator + (const Point& P) const; //add coordinates
    bool operator == (const Point& P) const; // comparing point objects
    Point& operator = (const Point& source); //Assignment operator
    Point& operator *=(double factor); //scale coordinates and assign
    
    //Global operator overloading
    friend Point operator * (double factor, const Point& P); //scale coordinates
    friend ostream& operator << (ostream& os, const Point& P); //printing point from cout
};
}}
#endif /* defined(__Sec3_4_Ex2__Point__) */
