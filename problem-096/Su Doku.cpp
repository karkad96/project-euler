#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 9;

int A[N][N] = { 0 };

bool checkColumn(int r, int c, int n)
{
    for (int i = 0; i < N; i++)
        if (A[i][c] == n)
            return false;

    return true;
}

bool checkRow(int r, int c, int n)
{
    for (int i = 0; i < N; i++)
        if (A[r][i] == n)
            return false;

    return true;
}

bool checkSquare(int r, int c, int n)
{
    r = r - r % 3;
    c = c - c % 3;

    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            if (A[i][j] == n)
                return false;
        }
    }

    return true;
}

bool checkAll(int r, int c, int n)
{
    return checkColumn(r, c, n) and checkRow(r, c, n) and checkSquare(r, c, n);
}

bool findFirstEmpty(int& i, int& j)
{
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (!A[i][j])
                return true;
        }
    }

    return false;
}

bool solveSudoku()
{
    int r;
    int c;

    if (!findFirstEmpty(r, c))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (checkAll(r, c, num))
        {
            A[r][c] = num;

            if (solveSudoku())
                return true;

            A[r][c] = 0;
        }
    }

    return false;
}

int main()
{
    fstream file("sudoku.txt");
    string line;

    int it = 0;
    int res = 0;

    while (getline(file, line))
    {
        if (line[0] == 'G')
            continue;

        for (int i = 0; i < 9; i++)
            A[it][i] = line[i] - '0';

        it = (it + 1) % 9;

        if (it == 0)
        {
            if (solveSudoku())
            {
                res += 100 * A[0][0] + 10 * A[0][1] + A[0][2];
            }
        }
    }

    cout << res << endl;

    return 0;
}