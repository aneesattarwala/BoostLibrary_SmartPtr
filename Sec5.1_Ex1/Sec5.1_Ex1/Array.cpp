//
//  File.cpp
//  Copyright (c) 2015 MichaelScott. All rights reserved.

// putting array class and functions in Anees::Containers namespace
// Templatizing Array to handle varous shapes and use of static variable


#ifndef Array_CPP
#define Array_CPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include"ArrayException.hpp"

namespace Anees{namespace Containers{
    
    template <class T>
    
    Array<T>::Array()  //default constructor with 5 elements 
    {
        m_size=5;
        m_data= new T[m_size];
//        cout<<"Point array with 5 points created!"<<endl;
    }
    
    template <class T>
    Array<T>::Array(int n)  // constructor with user given elements 
    {
        m_size=n;
        m_data=new T[m_size];
//        cout<<"Array with "<<m_size<<" points created!"<<endl;
    }
    
    template <class T>
    Array<T>::Array (const Array<T>& A) //copy constructor performing deep copy
    {
        m_size=A.m_size;
        m_data=new T[m_size];   // creating new memory for new object to be created using copy ctr.
        for (int i=0; i<m_size;i++)
        {
            m_data[i]=A.m_data[i];
        }
        //  cout<<"Array array created via copy construction!"<<endl;
    }
    
    template <class T>
    Array<T>::~Array()  // destructor for array 
    {
        delete [] m_data;
        // cout<<"Array deleted!"<<endl;
    }
    
    template <class T>
    Array<T>& Array<T>::operator=(const Array<T>& A)  // Assignment operator
    {
        if (this==&A)     // avoiding self-assignment
        {
            return *this;
        }
        delete [] m_data;              // deleting current memoory.
        m_size=A.m_size;
        m_data=new T[m_size];  // creating new memory for current object being assigned to
        for (int i=0; i<m_size;i++)
        {
            m_data[i]=A.m_data[i];
        }
        return *this;     // return pointer to current object being assigned to
    }
    
    // Read-write operator - > Reference returned can be modified as it is not "const"
    template <class T>
    T& Array<T>::operator[](int index)  //[] operator for array indexing
    {
        if (index>-1 && index < m_size)
        {
            return (m_data[index]);     // returning index value
        }
        else
            throw OutofBoundsException(index) ;  // if index out of bounds throw exception object.
    }
    
    // Read only operator -> Reference returned cannot be modified as it is "const T&"
    template <class T>
    const T& Array<T>::operator[](int index) const //const version of [] operator
    {
        
        if (index>-1 && index<m_size)
        {
            return (m_data[index]);     // returning index value
        }
        else
            throw OutofBoundsException(index);      // if index out of bounds throw exception object.
        
    }
    
    template <class T>
    int Array<T>::size() const // returns size of array
    {
        return m_size;
    }
    
    template <class T>
    void Array<T>::SetElement(const T& P, int n)  // sets an element in the Array at position n
    {
        if(n>-1 && n< m_size)
        {
            m_data[n]= P;
        }
        else
            throw OutofBoundsException(n);         // if index out of bounds throw exception object.
    }
    
    template <class T>
    T& Array<T>::GetElement(int n) const // return  element from array at position n
    {
        if (n>-1 && n<m_size)
        {
            return (m_data[n]);
        }
        else
            
            throw OutofBoundsException(n);          // if index out of bounds throw exception object.
        
    }
}}


#endif 
