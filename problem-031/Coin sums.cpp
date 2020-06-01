#include <iostream>

using namespace std;

int main()
{
    const int N = 200;

    int coins[] = { 1,2,5,10,20,50,100,200 };

    int ways[N + 1] = { 0 };

    ways[0] = 1;

    for (auto i : coins)
        for (int j = i; j <= 200; j++)
            ways[j] += ways[j - i];

    cout << ways[200] << endl;

    return 0;
}