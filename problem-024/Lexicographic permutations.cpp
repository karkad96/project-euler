#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int perm[] = { 0,1,2,3,4,5,6,7,8,9 };
    long int i = 1;
    int n = 1000000;

    do {

        if (i == n)
            break;
        i++;
    } while (next_permutation(perm, perm + 10));

    for (int i = 0; i < 10; i++)
        cout << perm[i];

    cout << endl;

    return 0;
}
