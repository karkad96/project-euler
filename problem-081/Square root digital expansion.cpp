#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const int N = 80;
int A[N][N] = { 0 };

int main()
{
    int it = 0;
    int jt = 0;

    fstream file("matrix.txt");
    string line;

    vector<int> v;

    while (getline(file, line))
    {
        stringstream ss(line);


        for (int i; ss >> i;) {
            A[it][jt] = i;
            if (ss.peek() == ',')
                ss.ignore();

            jt++;
        }

        it++;
        jt = 0;
    }

    for (int i = 1; i < N; i++)
    {
        A[0][i] += A[0][i - 1];
        A[i][0] += A[i - 1][0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            A[i][j] += min(A[i - 1][j], A[i][j - 1]);
        }
    }

    cout << A[N - 1][N - 1] << endl;

    return 0;
}