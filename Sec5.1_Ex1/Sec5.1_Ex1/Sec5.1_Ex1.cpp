//  main.cpp
//  Sec5.1_Ex1
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Demonstration of shared pointers using array of various shapes.
// Array consisting of shared pointers, pointing to various shape objects is created.
// Reference count of shared pointers is checked after array creation and after array goes out of scope.

#include <iostream>
#include"Shape.hpp"
#include"Array.hpp"
#include"Point.hpp"
#include"Line.hpp"
#include"Circle.hpp"
#include<boost/shared_ptr.hpp>
using namespace Anees::Containers;
using namespace Anees::CAD;
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;
int main()
{
    ShapePtr P(new Point(1,2));               // Pointer to Point
    ShapePtr L(new Line(Point(1,2),Point(3,4)));  // Pointer to Line
    ShapePtr C(new Circle(1,Point(1,2)));              // Pointer to Circle
    
    //counting reference for shared pointers. It is one as only main is using the pointers.
    
    cout<<"****Reference Counts in Outerscope****"<<endl;
    cout<<"Point object :"<<P.use_count()<<endl;
    cout<<"Line object :"<<L.use_count()<<endl;
    cout<<"Circle object :"<<C.use_count()<<endl;
    {
        ShapeArray SA(3);    // Creating array of point, line and circle
        SA[0]=P;
        SA[1]=L;
        SA[2]=C;
        
        // counting references for each shape. Should be 2 since each shared pointer is shared by shape array and main program
        cout<<endl;
        cout<<"****Reference Counts in Innerscope****"<<endl;
        cout<<"Point object :"<<P.use_count()<<endl;
        cout<<"Line object :"<<L.use_count()<<endl;
        cout<<"Circle object :"<<C.use_count()<<endl;
        
        // printing elements of array
        cout<<endl;
        cout<<"Various shapes in shape array :"<<endl;
        for(int i=0; i<3;++i){
            cout<<SA[i]->ToString()<<endl;}
        
    }   // Shapes of point, line and circle shared by Shape array go out of scope here and are automatically deleted. The reference count is 1 now as as they are not required by ShapeArray. These shapes are only present in main.   

    cout<<endl;
    cout<<"****Reference Counts in Outerscope once again****"<<endl;
    cout<<"Point object :"<<P.use_count()<<endl;
    cout<<"Line object :"<<L.use_count()<<endl;
    cout<<"Circle object :"<<C.use_count()<<endl;

    return 0;
}

