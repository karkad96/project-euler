#include <iostream>

using namespace std;


int main()
{
    const int N = 100;

    int ways[N + 1] = { 0 };

    ways[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            ways[j] += ways[j - i];
        }
    }

    cout << ways[100] - 1 << endl;

    return 0;
}