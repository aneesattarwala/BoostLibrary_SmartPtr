//  Copyright (c) 2015 MichaelScott. All rights reserved.
//Circle class with center and radius. Memeber functions include - constructors, copy constructor and destructor, diameter, circumference,area of circle and printing the description of circle.
// added assignment operator and overaloaded << operator to print via cout using friend function.

#ifndef __Sec3_4_Ex2__Circle__
#define __Sec3_4_Ex2__Circle__

#include <iostream>
#include <string>
#include "Point.hpp"
#include "Shape.hpp"
namespace Anees{namespace CAD{


class Circle:public Shape
{
private:
    double m_radius;              //radius of circle
    Point CentrePoint;            // centre of circle
public:
    //constructors and destructors
    Circle();                          //default constructor with radius 1 and centre (0,0)
    Circle(double r, const Point& Pt); // intializing circle with given radius and centre
    Circle(const Circle& C);          //copy constructor
    ~Circle();                        //destructor
    
    //Accessing functions
    double Radius() const;          //get radius
    Point Centre() const;           //get centre point
    void Radius(double r);         // set radius
    void Centre(const Point& Pt);   //set center point
    
    //modifier functions
    double Diameter() const;       // calculate diamater of circle
    double Area() const;           // calculate area of circle
    double Circumference() const;  // calculate circumference of circle
    string ToString() const; //Return string description of circle
    void Draw() const;      //Draw method overriden by Circle class
    //Assignment operator
    Circle& operator = (const Circle& source);
    
    //Global operator overloading
    friend ostream& operator << (ostream& os, const Circle& c); //printing point from cout
};
}}

#endif /* defined(__Sec3_4_Ex2__Circle__) */
