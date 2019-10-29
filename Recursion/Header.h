#include <iostream>
#include <cmath>

using namespace std;

double f1(double x)
{ 
	return 2 * x * x + x + 1; 
}

double f2(double x)
{
	return x*x + 4;
}

typedef double (*FP) (double x); 

double Q(FP fp, double a, double b, double err) 
{ 
	double c = (a + b) / 2;
	double error = fabs((.5*((fp(a) + fp(b))*(b - a))) - ((.5*((fp(a) + fp(c))*(c - a))) + (.5*((fp(c) + fp(b))*(b - c)))));
	//system("pause");
	if (error <= err)
	{
		//cout << "error < 0.001:\n";
		return (.5*((fp(a) + fp(b))*(b - a)));
	}
	else
	{
		
		return (Q(fp, c, b, err) + Q(fp, a, c, err));
	}
} 
