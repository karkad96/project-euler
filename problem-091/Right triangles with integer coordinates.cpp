#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	int pom;

	while (b != 0)
	{
		pom = b;
		b = a % b;
		a = pom;
	}

	return a;
}

int main()
{
	const int N = 50;
	int res = 3 * N * N;

	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			int fact = gcd(x, y);
			res += min(y * fact / x, (N - x) * fact / y) * 2;
		}
	}

	cout << res << endl;

	return 0;
}