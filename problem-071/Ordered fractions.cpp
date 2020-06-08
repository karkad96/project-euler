#include <iostream>

using namespace std;

//https://en.wikipedia.org/wiki/Farey_sequence

int main()
{
    int a = 2;
    int b = 5;
    int c = 3;
    int d = 7;

    while (b + d < 1000000)
    {
        a = a + c;
        b = b + d;
    }

    cout << a << endl;

    return 0;
}