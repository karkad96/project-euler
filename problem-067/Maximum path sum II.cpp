#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <algorithm>

using namespace std;

const int N = 100;

int A[N][N];

int main()
{
    ifstream file("triangle.txt");
    string line;

    int line_number = 0;

    while (getline(file, line))
    {
        stringstream stream(line);
        int tmp;
        int it = 0;

        while (stream >> tmp)
        {
            A[line_number][it++] = tmp;
        }

        line_number++;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            A[i - 1][j] = max(A[i - 1][j] + A[i][j], A[i - 1][j] + A[i][j + 1]);
        }
    }

    cout << A[0][0] << endl;

    return 0;
}