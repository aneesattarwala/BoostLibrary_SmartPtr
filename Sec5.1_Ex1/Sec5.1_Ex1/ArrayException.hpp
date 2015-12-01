//
//  ArrayException.hpp
//  Sec3.6_Ex2
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Exception class to throw exception objects

#ifndef __Sec3_6_Ex2__ArrayException__
#define __Sec3_6_Ex2__ArrayException__
#include <iostream>
#include<string>
namespace Anees{namespace Containers{
class ArrayException
{
public:
   virtual std::string GetMessage() const=0;   // creating PVMF so that ArrayException is ABC
    
};
}}
#endif /* defined(__Sec3_6_Ex2__ArrayException__) */