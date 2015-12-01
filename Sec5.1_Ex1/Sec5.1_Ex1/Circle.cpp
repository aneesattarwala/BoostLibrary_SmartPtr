//  Circle.cpp
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//Circle class with center and radius. Memeber functions include - constructors, copy constructor and destructor, diameter, circumference,area of circle and printing the description of circle.
// added assignment operator and overaloaded << operator to print via cout using friend function.
// Implemented colon syntax for Circle class

#include "Shape.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <sstream>
#include "Circle.hpp"
#include "Point.hpp"
namespace Anees{namespace CAD{
Circle::Circle():Shape(),CentrePoint(0,0),m_radius(1)  // default constructor with base ctr
{
//    cout<<"Default circle created!"<<endl;
}

//circle with given radius and centre point and base ctr

Circle::Circle(double r, const Point& Pt):Shape(),CentrePoint(Pt),m_radius(r)  {
    //cout<<"Default circle created!"<<endl;
}

// copy constructor including base copy
Circle::Circle(const Circle& C):Shape(C),CentrePoint(C.CentrePoint),m_radius(C.m_radius)
{
    //cout<<"Circle copy constructed!"<<endl;
}

Circle::~Circle()                   // destructor
{
    //cout<<"Circle destroyed!"<<endl;
}

double Circle::Radius() const       // get radius
{
    return m_radius;
}

Point Circle::Centre() const        // get centre point
{
    return CentrePoint;
}

void Circle::Radius(double r)  //set radius
{
    m_radius=r;
}
void Circle::Centre(const Point&Pt) //set centre point
{
    CentrePoint=Pt;
}

// modifier functions
double Circle::Diameter() const   // calculate diameter of circle object
{
    return(2*m_radius);
}

double Circle::Area() const       // caculate area of circle object
{
    return (M_PI*pow(m_radius,2));
}

double Circle::Circumference() const  // calculate circumference of circle object
{
    return (2*M_PI*m_radius);
}

string Circle::ToString() const
{
    stringstream ss;    //using stringstream object ss to create text in required format
    string sendstring;
    string s=Shape::ToString();
    ss<<s<<" Circle has centre "<<CentrePoint.ToString()<<" and radius "<<m_radius;
    sendstring=ss.str();        //returning the string as required using str()
    return sendstring;
}

void Circle::Draw()const // Draw() method overriden by Circle` class
{
    cout<<"Draw method of Circle class called!"<< endl;
}
//Assignemnt operator with base class = operator
Circle& Circle:: operator= (const Circle& source)
{
    if(this ==&source)
        return *this;
    Shape::operator=(source);
    m_radius=source.m_radius;
    CentrePoint=source.CentrePoint;
    return *this;
}


// Global operator
ostream& operator << (ostream& os, const Circle& c) //printing point from cout
{
    
    os<<"Circle has center at "<<c.CentrePoint<<" and radius "<<c.m_radius;
    return os;
}
}}


