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

double f3(double x)
{
	return (2 * (x*x*x) - 10 * (x*x) + 500);
}

typedef double(*FP) (double x);

double Q(FP fp, double a, double b, double err)
{
	double c = (a + b) / 2;
	double error = fabs((.5*((fp(a) + fp(b))*(b - a))) - ((.5*((fp(a) + fp(c))*(c - a))) + (.5*((fp(c) + fp(b))*(b - c)))));
	if (error <= err)
	{
		return (.5*((fp(a) + fp(b))*(b - a)));
	}
	else
	{
		return (Q(fp, c, b, err) + Q(fp, a, c, err));
	}
}

double findRoot(FP fp, double a, double b, double err)
{
	double c = (a + b) / 2;
	if ((b - c) <= err)
	{
		return c;
	}
	else
	{
		if (fp(a) * fp(c) <= 0)
			b = c;
		else
			a = c;
		return findRoot(fp, a, b, err);
	}
}

int main()
{
	cout << "Area of 2x^2 + x + 1 at interval [1 5] = " << Q(&f1, 1.0, 5.0, 0.001) << endl << endl;
	cout << "Area of x^2 + 4 at interval [0 4] = " << Q(&f2, 0, 4.0, 0.001) << endl << endl;

	cout << "The root of f(x) = 2x^3 - 10x^2 +500 is : " << findRoot(&f3, -9, 9, 0.001) << endl << endl;
	system("PAUSE");
}