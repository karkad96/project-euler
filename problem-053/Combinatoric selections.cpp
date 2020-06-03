#include <iostream>

using namespace std;

const int N = 100;
int binomial[N + 1][N + 1];

int main()
{
    for (int i = 0; i <= N; i++)
    {
        binomial[i][i] = binomial[i][0] = 1;

        for (int j = 1; j < i; j++)
        {
            if (binomial[i - 1][j - 1] + binomial[i - 1][j] <= 1000000 and binomial[i - 1][j] and binomial[i - 1][j - 1])
                binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
            else
                break;
        }

        for (int j = i - 1; j >= 1; j--)
        {
            if (binomial[i - 1][j - 1] + binomial[i - 1][j] <= 1000000 and binomial[i - 1][j] and binomial[i - 1][j - 1])
                binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
            else
                break;
        }
    }

    int count = 0;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!binomial[i][j])
                count++;
        }
    }

    cout << count << endl;

    return 0;
}