//
//  Visitor.cpp
//  Sec5.1_Ex3
//
//  Created by Anees Attarwala on 5/4/15.
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//

#include "Visitor.hpp"
#include <boost/variant.hpp>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
using namespace std;
using boost::variant;
namespace Anees {namespace CAD{
    
    void Visitor::operator() (Point &P) const    //operator definition for point
    {
        P.X(P.X()+x);
        P.Y(P.Y()+y);
    }

    void Visitor::operator() (Line &L) const //operator definition for line
    {
        L.Start(Point(L.Start().X()+x,L.Start().Y()+y));
        L.End(Point(L.End().X()+x,L.End().Y()+y));
    }
    
    void Visitor::operator() (Circle &C) const  //operator definition for circle only offsets centre, keeping radius same
    {
        C.Centre(Point(C.Centre().X()+x,C.Centre().Y()+y));
    }
}}