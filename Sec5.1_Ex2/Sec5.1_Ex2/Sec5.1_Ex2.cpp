//  main.cpp
//  Sec5.1_Ex2
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  In this exercise, create a typedef for a Person tuple that contains a name, age and length. Also create a function that prints the person tuple. Use the get<T>() member functions the retrieve the data. Create a few person tuple instances and print them.
//  Also increment the age of one of the persons. Note that to change a value of one of the tuple elements, you can also use the get<T>() function since it returns a reference to the value.

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <string>
#include <iostream>
using namespace std;

typedef boost::tuple<string,double,double> Person;  //typedefin tuple to Person
void Printtuple (Person& P)
{
    cout<<P.get<0>()<<" "<<P.get<1>()<<" "<<P.get<2>()<<endl;
}



int main()
{ 
    Person A("Alpha",15,10);   //Creating person tuples
    Person B("Beta",20,10.4);
    Person C("Gamma",25,11.2);
    Person D("Delta",35,12.3);
    Person E= D;
    
    /******PRINTING TUPLES*******************/
    Printtuple(A);
    Printtuple(B);
    Printtuple(C);
    Printtuple(D);
    Printtuple(E);
    cout<<endl;
    
  /**** INCREMENT PERSON A's AGE********/
    A.get<1>()=A.get<1>()+1;
    Printtuple(A);
    return 0;
}

