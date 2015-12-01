//  main.cpp
//  Sec5.1_Ex3
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Thus create a typedef for a ShapeType variant that can contain a Point, Line or Circle. Next create a function that returns the variant. Within this function ask the user for the shape type to create. Then create the requested shape and assign it to the variant and return it.

#include <iostream>
#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Visitor.hpp"
using namespace std;
using boost::variant;
using namespace Anees::CAD;
typedef variant<Point,Line,Circle> ShapeType;  //typedef-ing shape type variant

ShapeType ReturnShape()
{
    int choice;
    cout<<"What shape do you want to create - 1) Point, 2)Line, 3) Circle?";
    cin>>choice;
    switch(choice)
    {
        case (1):
            double x,y;          // Point coordinates
            cout<<"Enter x :";cin>>x;
            cout<<"Enter y :";cin>>y;
            return (Point(x,y));
            break;
         
        case (2):
            double x1,y1,x2,y2;      // coordinates for begin and end point
            cout<<"Enter x1 :";cin>>x1;
            cout<<"Enter y1 :";cin>>y1;
            cout<<"Enter x2 :";cin>>x2;
            cout<<"Enter y2 :";cin>>y2;
            return (Line(Point(x1,y1),Point(x2,y2)));
            break;
          
        case (3):
            double a,b,r;                 //circle center coordinates and radius
            cout<<"Enter x :";cin>>a;
            cout<<"Enter y :";cin>>b;
            cout<<"Enter radius :";cin>>r;
            return (Circle(r,Point(a,b)));
            break;
            
        default:
            cout<<"Wrong choice! returing default point"<<endl;
            break;
    }
   return Point(0,0);
    
}

/*In the main program, call the function and print the result by sending it to cout. */
int main()
{
    ShapeType UserShape;
    UserShape=ReturnShape();
    cout<<UserShape<<endl;

    /** TESTING EXCEPTION WHEN USERSHAPE IS NOT LINE*******/
    try{
        Line LineObj;
        LineObj = boost::get<Line>(UserShape);   // assigning lineobj to variant
        cout<<"Variant Line assigned to LineObj!"<<endl;
        cout<<LineObj<<endl;
     }
    catch (boost::bad_get& err)
        {
        cout << "Error..cannot assign to LineObj as variant is not Line: " << err.what() << endl;
        }
    
/*******MOVING VARIOUS SHAPES USING boost::apply_visitor(visitor,variant) GLOBAL FUNCTION***/ 
    
    double off_x,off_y;  // offset coordinates
    cout<<"Enter offset x coordinate:";cin>>off_x;
    cout<<"Enter offset y coordinate:";cin>>off_y;
    Visitor V(off_x,off_y);  //constructing Visitor using offset coordinates
    
    boost::apply_visitor(V,UserShape);  //applying the move
    
    cout<<"**********SHAPE MOVED BY VISITOR POINT (1,2) IS BELOW*******"<<endl<<endl;
    cout<<UserShape;
    return 0;
}

