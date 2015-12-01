
//  OutOfBoundsException.h
//  Sec3.6_Ex2
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//

#ifndef __Sec3_6_Ex2__OutOfBoundsException__
#define __Sec3_6_Ex2__OutOfBoundsException__
#include "ArrayException.hpp"
#include <iostream>
#include <string>
#include<sstream>
using namespace std;
namespace Anees{namespace Containers{
class OutofBoundsException:public ArrayException
{
private:
    int m_index;
public:
    OutofBoundsException(int n):m_index(n){};            //constructor
    inline std::string GetMessage() const          //print handle message
    {
        stringstream ss;
        ss<<"Out of bounds!"<<endl;
        return (ss.str());
    }
};
    class UnequalSizeException:public ArrayException
    {
    private:
        int m_size;
    public:
        UnequalSizeException(int n):m_size(n){};            //constructor
        inline std::string GetMessage() const          //print handle message
        {
            stringstream ss;
            ss<<"Cannot compute. Unequal sizes!"<<endl;
            return (ss.str());
        }
    };
}}
#endif /* defined(__Sec3_6_Ex2__OutOfBoundsException__) */
