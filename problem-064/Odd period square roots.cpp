#include <iostream>

using namespace std;

//https://en.wikipedia.org/wiki/Periodic_continued_fraction

int main()
{
    int res = 0;

    for (int N = 1; N <= 10000; N++)
    {
        if (sqrt(N) == (int)sqrt(N))
            continue;

        int sqr = (int)sqrt(N);
        int m_1 = 0;
        int d_1 = 1;
        int a_1 = sqr;

        int m = -1;
        int d = -1;
        int a = -1;

        int count = 0;

        while (d != 1)
        {
            m = d_1 * a_1 - m_1;
            d = (N - m * m) / d_1;
            a = (sqr + m) / d;

            m_1 = m;
            d_1 = d;
            a_1 = a;

            count++;
        }

        if (count % 2 == 1)
            res++;
    }

    cout << res << endl;

    return 0;
}