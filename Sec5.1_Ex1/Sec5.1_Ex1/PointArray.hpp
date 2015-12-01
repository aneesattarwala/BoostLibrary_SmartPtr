
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//Pointarray inherited from array template class - concrete inheritence

#ifndef PointArray_cpp
#define PointArray_cpp

#include "Point.hpp"
#include "Array.hpp"
#include "Shape.hpp"
using namespace Anees::CAD;
namespace Anees {namespace Containers{

class PointArray:public Array<Point>    //inheriting PointArray as array of points.
                                               
{
public:
    //constructors and destructors
    PointArray();    //constructor
    PointArray(int n);    //constructor with size n elements
    PointArray (const PointArray&Pt); // copy constructor
    ~PointArray();   //destructor
    
    //functionality
    double Length() const; // returns total length between points in array,
    
    //operators
    PointArray& operator = (const PointArray& source); //Assignment operator
};
}}

    
#endif /* defined(__Sec3_4_Ex2__Point__) */
