//  Sec5.1_Ex5
//  Copyright (c) 2015 MichaelScott. All rights reserved.


#include <iostream>

// TestNormal.cpp
//
// Testing code for Poisson and Exponential distributions
//
// Look at the Normal distribution because it is important.
// And gamma distribution

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/Poisson.hpp>
  

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;
    
	exponential_distribution<> myExponential(10); // Default type is 'double'
	cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;
    
	// Distributional properties
	double x = 10.25;
    
	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;
    
	// Choose another data type and now a Exponential(1) variate
	normal_distribution<float> myExponential2(1);
	cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << endl;
	
	cout << "pdf: " << pdf(myExponential2, x) << endl;
	cout << "cdf: " << cdf(myExponential2, x) << endl;
    
	// Choose precision
	cout.precision(10); // Number of values behind the comma
    
	// Other properties
	cout << "\n***Exponential distribution: \n";
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;
    
	// Poisson distribution

	poisson_distribution<double> myPoisson(10);
    
	double val = 13.0;
	cout << endl <<  "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;
    
	vector<double> pdfList;
	vector<double> cdfList;
    
	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions
    
	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));
        
		val += h;
	}
    
    cout<<"*******Pdf for Poisson distribution**********"<<endl;
    
	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";
        
	}
    
    cout<<"*******Cdf for Poisson distribution**********"<<endl;
    
	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";
        
	}
    
	return 0;
}