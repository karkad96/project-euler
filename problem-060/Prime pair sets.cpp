#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000000;

int primes[N + 1];
int nth[N + 1];
int nth_prime[N + 1];

vector<vector<int>> v;

struct node
{
    int data;
    node* next;
};

void ES()
{
    for (int i = 0; i <= N; i++)
        primes[i] = true;

    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                primes[j] = false;
            }
        }
    }
}

bool isPrime(int n)
{
    if (n <= N)
        return primes[n];

    if (n > 2 and n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

int length(int n)
{
    return (int)log10(n) + 1;
}

bool concat(int n, int k)
{
    int size = (int)pow(10, length(k));
    int tmp = n * size + k;

    if (!isPrime(tmp))
        return false;

    size = (int)pow(10, length(n));
    tmp = k * size + n;

    if (!isPrime(tmp))
        return false;

    return true;
}

int main()
{
    ES();
    int y = 0;
    for (int i = 3; i <= N; i++)
    {
        if (primes[i])
        {
            nth[i] = y;
            nth_prime[y] = i;
            y++;
        }
    }

    const int limit = 10000;

    for (int i = 3; i < limit; i += 2)
    {
        if (primes[i])
        {
            vector<int> tmp;

            for (int j = i + 2; j < limit; j += 2)
            {
                if (primes[j])
                {
                    if (concat(i, j))
                    {
                        tmp.push_back(j);
                    }
                }
            }

            v.push_back(tmp);
        }
    }

    int res = 0;
    bool flag = false;

    for (unsigned int i = 0; i < v.size() and !flag; i++)
    {
        for (unsigned int j = i + 1; j < v.size() and !flag; j++)
        {
            vector<int> v1;

            set_intersection(v[i].begin(), v[i].end(),
                v[j].begin(), v[j].end(), back_inserter(v1));

            if (v1.size() > 0)
            {
                for (unsigned int k = 0; k < v1.size() and !flag; k++)
                {
                    vector<int> v2;

                    set_intersection(v[nth[v1[k]]].begin(), v[nth[v1[k]]].end(),
                        v1.begin(), v1.end(), back_inserter(v2));

                    if (v2.size() > 0)
                    {
                        for (unsigned int l = 0; l < v2.size() and !flag; l++)
                        {
                            vector<int> v3;

                            set_intersection(v[nth[v2[l]]].begin(), v[nth[v2[l]]].end(),
                                v2.begin(), v2.end(), back_inserter(v3));

                            if (v3.size() > 0)
                            {
                                res += nth_prime[i] + nth_prime[j] + v1[k] + v2[l] + v3[0];
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}