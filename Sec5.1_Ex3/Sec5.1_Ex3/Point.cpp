//  Point.cpp
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Point class with cartesian coordiantes. Functionalities include returning and setting (x,y) points, a string function that returns text description of the point and distance functions to calculate distance between 2 points.
// Added operators to perform various functions like addition, negation, multiplications and assignments and printing with cout.

#include "Point.hpp"
#include"Shape.hpp"
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
namespace Anees{namespace CAD{

Point::Point() : Shape(),m_x(0),m_y(0) //default constructor with base class ctr
{
    //cout<<"Point object created!"<<endl;
}


Point::Point(double x, double y) : Shape(), m_x(x),m_y(y) //default constructor with base class ctr
{
//    cout<<"Point object created with user inputs!"<<endl;
}

Point::Point(const Point& Pt): Shape(Pt),m_x(Pt.m_x),m_y(Pt.m_y)  //copy ctr with base class ctr

{
 //   cout<<"Point object created with copy constructor!"<<endl;
}

Point::~Point()               //destructor
{
    //cout<<"Point object destroyed!"<<endl;
}


double Point::X() const  //returning x coordinate
{
    return m_x;
}

double Point::Y() const //returning y coordinate
{
    return m_y;
}

void Point::X(double a)  //setting x coordinate
{
    m_x= a;
}

void Point::Y(double b)  //setting y coordinate
{
    m_y= b;
}

string Point::ToString() const  // to return coordinates as string
{
    stringstream ss;            //using stringstream object ss to create text in required format
    string s=Shape::ToString();
    string sendstring;
    ss<<s<<" Point("<<m_x<<","<<m_y<<")";
    sendstring=ss.str();        //returning the string as Point(x,y) as required using str()
    return sendstring;
}

double Point::Distance() const //calculating distance from origin as sqrt(x^2+y^2)
{
    return(sqrt(pow(m_x,2)+pow(m_y,2)));
}

double Point::Distance(const Point& Pt) const //calculating distance between two points
{
    return (sqrt(pow(Pt.m_x-m_x,2)+pow(Pt.m_y-m_y,2)));
}

void Point::Draw() const  // Draw method overridden by point class
{
  cout<<"Draw method of Point class called!"<< endl;
}
    
    
Point Point::operator - () const // Negate coordinates
{
    return Point (-m_x,-m_y);
}


Point Point::operator * (double factor) const //scale coordinates by a factor
{
    return Point (m_x*factor, m_y*factor);
}

Point Point:: operator + (const Point& P) const//add coordinates
{
    return Point(m_x+P.m_x,m_y+P.m_y);
}


bool Point:: operator == (const Point& P) const // comparing point objects
{
    return bool(m_x==P.m_x && m_y==P.m_y);
    
}


Point& Point::operator = (const Point& source) //Assignment operator
{
    
    if(this==&source)               // avoid self-assignment
        return *this;
    
   Shape::operator=(source);     // call base class assignment operator for base part
    m_x=source.m_x;
    m_y=source.m_y;
    return *this;
}

Point& Point::operator *=(double factor) //scale coordinates and assign
{
    m_x*=factor;
    m_y*=factor;
    return *this;
}

//Global operator overloading
Point operator * (double factor,const Point& P) //scale coordinates
{
    return (P*factor);
}

ostream& operator << (ostream& os, const Point& P) //printing point from cout
{
    stringstream s;
    os<<"Point ("<<P.m_x<<","<<P.m_y<<")";
    return os;
}
}}

