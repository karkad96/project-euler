#include <iostream>

using namespace std;

//https://en.wikipedia.org/wiki/Farey_sequence

int main()
{
    int limit = 12000;
    int a = 1;
    int b = 3;
    int c = 4000;
    int d = 11999;
    int count = 0;

    while (c != 1 or d != 2)
    {
        count++;
        int k = (limit + b) / d;
        int e = k * c - a;
        int f = k * d - b;
        a = c;
        b = d;
        c = e;
        d = f;
    }

    cout << count << endl;

    return 0;
}