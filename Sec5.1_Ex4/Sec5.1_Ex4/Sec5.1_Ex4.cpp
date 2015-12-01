//  main.cpp
//  Sec5.1_Ex4
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Uniform random number generator illustration

#include <iostream>
#include <boost/random.hpp>
#include<map>

using namespace std; 
int main()
{
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;
    
    //Set the seed
    myRng.seed(static_cast<boost::uint32_t>(time(0)));
    
    //Uniform ins range[1,6]
    boost::random::uniform_int_distribution<int> six(1,6);
    
    //map that holds frequency of each outcome
    map<int,long> statistics;     // int to hold outcome and long to hold frequency
    int outcome;                  //current outcome
    int n;                       // number of trials
    cout<<"How many trials?";
    cin>>n;
    
    for (int i=1; i<=n;++i)     //generating n random outcome
    {
        outcome = six(myRng);
        statistics[outcome]++;  //counting outcome [1-6] of each trial
        
    }
    for (int i=1;i<=6;++i)
    {
        cout<<"Trial "<<i<<" has "<<setprecision(6)<<double(statistics[i])/double(n)*100<<"% outcomes"<<endl;
    }
    return 0;
}

