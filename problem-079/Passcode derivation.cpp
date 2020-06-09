#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int A[10][10] = { 0 };

    ifstream file("keylog.txt");
    string line;

    while (getline(file, line))
    {
        int a = (int)line[0] - '0';
        int b = (int)line[1] - '0';
        int c = (int)line[2] - '0';

        A[a][b]++;
        A[a][c]++;
        A[b][c]++;
    }

    int B[10] = { 0 };

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (A[i][j])
                B[i]++;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int mx = 0;
        int zero = 0;

        for (int j = 0; j < 10; j++)
        {
            if (j != 4 and j != 5)
            {
                if (mx < B[j])
                {
                    mx = B[j];
                    zero = j;
                }
            }
        }
        cout << zero;
        B[zero] = 0;
    }

    return 0;
}