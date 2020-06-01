#include <iostream>

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
	const int N = 1000;

	int mark[N + 1] = { 0 };
	int mx = 0;
	int res = 0;

	for (int m = 1; 2 * m * m <= 1000; m++)
	{
		for (int n = 1; 2 * m * m + 2 * m * n <= 1000 and n < m; n++)
		{
			if ((m + n) % 2 == 0)
				continue;

			int p = 2 * m * m + 2 * m * n;
			int k = 1;

			while (k * p <= 1000)
			{
				mark[k * p]++;
				k++;
			}
		}
	}

	for (int i = 0; i <= N; i++)
	{
		if (mx < mark[i])
		{
			mx = mark[i];
			res = i;
		}
	}

	cout << res << endl;

	return 0;
}