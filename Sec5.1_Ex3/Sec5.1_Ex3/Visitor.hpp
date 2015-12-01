//
//  Visitor.h
//  Sec5.1_Ex3
//
//  Created by Anees Attarwala on 5/4/15.
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//
#ifndef __Sec5_1_Ex3__Visitor__
#define __Sec5_1_Ex3__Visitor__

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
using namespace std;
using boost::variant;
#include <iostream>
namespace Anees {namespace CAD{    
class Visitor:public boost::static_visitor<void>
    {
    private:
        double x,y;  // offest parameters for x and y
    public:
        Visitor(double a,double b):x(a),y(b){};  //constructor setting offset coordinates
        
        //Operator () for Point, Line and Shape
        void operator() (Point &P) const;
        void operator() (Line &L) const;
        void operator() (Circle &C) const;
    };
    
}}
#endif /* defined(__Sec5_1_Ex3__Visitor__) */
