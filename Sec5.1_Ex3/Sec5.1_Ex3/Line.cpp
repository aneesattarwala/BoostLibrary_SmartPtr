//  Line.cpp
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Line class with Point class objects. Line class implements functionalities like outputting lenght of line, description of line and has overloaded functions to initialize line object, copy line objects and getting and setting line points.
// Adding assignment operator and << operator to print out the line object using friend function.
// Implemented colon syntax for line class

#include"Shape.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
using namespace std;
namespace Anees{namespace CAD{

Line::Line():Shape(),Startpoint(0,0),Endpoint(0,0)//Default constructor- calling base class ctr
{
//    cout<<"Default line created!"<<endl;
}
//ctr with args calling base class ctr
Line::Line(const Point& start, const Point& end):Shape(),Startpoint(start),Endpoint(end)
{
    
//    cout<<"Line created with given points!"<<endl;
}

//copy ctr calling base class ctr

Line::Line(const Line&L):Shape(L),Startpoint(L.Startpoint),Endpoint(L.Endpoint)
{
    //cout<<"Copy constructor for line object called!"<<endl;
}

Line::~Line()                     //destructor
{
   // cout<<"Line destroyed!"<<endl;
}


Point Line::Start() const          //getter function to get start point
{
    return Startpoint;
}

Point Line::End() const            //getter function to get end point
{
    return Endpoint;
}

void Line::Start(const Point &Pt)   //setter function to set start point
{
    Startpoint=Pt;
}

void Line::End(const Point &Pt)    //setter function to set end point
{
    Endpoint=Pt;
}

string Line::ToString() const     //Returns string description of line
{
    
    stringstream ss;            //using stringstream object ss to create text in required format
    string sendstring;
    string s=Shape::ToString();
    ss<<s<<" Line runs from "<<Startpoint.ToString()<<" to "<<Endpoint.ToString()<<"and has length of "<<setprecision(4)<<Length();
    sendstring=ss.str();        //returning the string as required using str()
    return sendstring;
    
    
}
double Line:: Length() const // Calculate length of line object passed by reference. Using Distance
//function from Point class and applying delegation
{
    return (Endpoint.Distance(Startpoint));
    
}
    
void Line::Draw()const // Draw() method overriden by Line class
{
cout<<"Draw method of Line class called!"<< endl;
}

//Assignment operator calling base class assignment operator
Line& Line:: operator= (const Line& source)
{
    
    if(this ==&source)
        return *this;
    Shape::operator=(source);          // call base class operator to for base part
    Startpoint=source.Startpoint;
    Endpoint=source.Endpoint;
    return *this;
}


// Global operator
ostream& operator << (ostream& os, const Line& L) //printing point from cout
{
    
    os<<"Line runs from "<<L.Startpoint<<" to "<<L.Endpoint<<" and has length of "<<setprecision(4)<<L.Length();
    return os;
}
}}

