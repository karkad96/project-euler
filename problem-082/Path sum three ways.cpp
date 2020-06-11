nclude <iostream>
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

    int s[N] = { 0 };

    for (int i = 0; i < N; i++)
        s[i] = A[i][N - 1];

    for (int i = N - 2; i >= 0; i--)
    {
        s[0] += A[0][i];

        for (int j = 1; j < N; j++)
            s[j] = min(s[j - 1] + A[j][i], s[j] + A[j][i]);

        for (int j = N - 2; j >= 0; j--)
            s[j] = min(s[j], s[j + 1] + A[j][i]);
    }

    int res = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        res = min(res, s[i]);
    }

    cout << res << endl;

    return 0;
}