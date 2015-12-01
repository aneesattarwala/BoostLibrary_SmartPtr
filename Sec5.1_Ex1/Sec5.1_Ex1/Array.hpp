//  Copyright (c) 2015 MichaelScott. All rights reserved.

// putting array class and functions in Anees::Containers namespace
// Templatizing Array to handle varous shapes and use of static variable


#ifndef __Sec2_6_Ex1__File__
#define __Sec2_6_Ex1__File__

#include <iostream>
#include"Point.hpp"
#include"Shape.hpp"
namespace Anees{namespace Containers{
template <class T>
class Array
{
private:
    T *m_data;   // dynamic array of shape objects
    int m_size;           // size of array
public:
    //constructors and destructor
    Array();                // default constructor allocating 10 elements
    Array(int n);          // default constructor allocating size n elements
    Array(const Array<T>& A);      // copy constructor
    virtual ~Array();              // destructor
    
    //operator overloading
    Array<T>& operator=(const Array<T>& A); // assignment operator
    T& operator [] (int index); // [] square brackets operator for reading and writing elements
    const T& operator [] (int index) const; //[] const version of square [] operator
    
    //Accessor functions
    int size() const; // returns size of array
    void SetElement(const T& P,int n);  // sets an element in the array at position n
    T& GetElement(int n) const; // return an element from array at position n    
};
}}
#ifndef Array_CPP
#include "Array.cpp"
#endif


#endif /* defined(__Sec2_6_Ex1__File__) */
