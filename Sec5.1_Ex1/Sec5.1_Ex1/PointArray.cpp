//Pointarray inherited from array template class - concrete inheritence

#include <iostream>
#include <string>
#include "PointArray.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "Point.hpp"

using namespace std;
using namespace Anees::CAD;
namespace Anees {namespace Containers{

PointArray::PointArray():Array<Point>() //default constructor with base class ctr
{
    //cout<<"Point object created!"<<endl;
}

PointArray::PointArray(int n):Array<Point>(n) //constructor with base class ctr
{
    //cout<<"Point object created!"<<endl;
}
    

PointArray::PointArray(const PointArray& Pt): Array<Point>(Pt)//copy ctr with base class ctr

{
 //   cout<<"Point object created with copy constructor!"<<endl;
}

PointArray::~PointArray()               //destructor
{
    //cout<<"Point object destroyed!"<<endl;
}

double PointArray::Length() const //calculating total length between array points
{
    double length=0;
    for (int i=0; i<this->size()-1;++i)         // looping until last but one element
    {                                           // calculating distance between adjacent points
        length+=(*this)[i].Distance((*this)[i+1]);// using Distance function and summing it up.
    }
    return length;
}




PointArray& PointArray::operator = (const PointArray& source) //Assignment operator
{
    
    if(this==&source)               // avoid self-assignment
        return *this;
   Array<Point>::operator=(source);     // call base class assignment operator for base part
   return *this;
}

    
}}

