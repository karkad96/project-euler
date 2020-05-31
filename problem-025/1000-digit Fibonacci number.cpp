#include <iostream>

using namespace std;

int main()
{
	double phi = 1.6180339887498948482045;
	double digits = 1.0;

	int fib = 1;

	while (digits <= 999)
	{
		digits = (++fib) * log10(phi) - log10(5.0) / 2.0;
	}

	cout << fib << endl;

	return 0;
}