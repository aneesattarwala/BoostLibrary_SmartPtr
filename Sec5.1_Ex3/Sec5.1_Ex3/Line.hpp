//  Line.hpp
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Line class with Point class objects. Line class implements functionalities like outputting lenght of line, description of line and has overloaded functions to initialize line object, copy line objects and getting and setting line points.
// Adding assignment operator and << operator to print out the line object using friend function.

#ifndef __Sec3_4_Ex2__Line__
#define __Sec3_4_Ex2__Line__

#include <iostream>
#include"Shape.hpp"
#include"Point.hpp"
namespace Anees{namespace CAD{
    
class Line:public Shape
{
private:
    Point Startpoint;   //start and end points
    Point Endpoint;
public:
    //constructors and destructors
    
    Line(); //default constructor
    Line(const Point& start, const Point& end); //constructor to initialize line with given start and end points
    Line (const Line& L);         //copy constructor
    
    ~Line();                      //destructor
    
    // Accessing functions
    
    Point Start() const;  //get  start point
    Point End() const;    //get end point
    void Start(const Point& Pt);     // set start point
    void End(const Point& Pt);     // set end point
    string ToString() const; //Returns string description of line
    double Length() const; // Calculate length of line object passed by reference.
    void Draw() const; // Draw method overridden by line class
    //operators
    Line& operator = (const Line& source); //Assignment operator
    //Global operator overloading
    friend ostream& operator << (ostream& os, const Line& L); //printing point from cou
};
}}
#endif /* defined(__Sec3_4_Ex2__Line__) */


