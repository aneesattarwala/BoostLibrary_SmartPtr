//  Shape.hpp
//  Sec3.4_Ex2
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Header file for shape class as a base class from which shapes like point, line and circle will be inherited.
// Creating Shape class as ABC
//template method pattern

#ifndef __Sec3_4_Ex2__Shape__
#define __Sec3_4_Ex2__Shape__

#include <iostream>
#include <string>
using namespace std;
namespace Anees{namespace CAD{
class Shape
{
    
private:
    int m_id;
    
public:             //constructors and destructors
    
    Shape();   //constructor
    
    Shape (const Shape& S); // copy constructor
    virtual ~Shape();   //destructor
    
    //Accessing functions
    int ID() const;  //Get shape ID
    virtual string ToString() const; // Get shape ID as ID:123;
    void Print() const;      // Print shape information from cout
    
    // operator overloading
    Shape& operator = (const Shape& source);  // Assignment operator
    
    // Pure virtual member function Draw() to create ABC
    virtual void Draw() const=0;
};
}}



#endif /* defined(__Sec3_4_Ex2__Shape__) */
