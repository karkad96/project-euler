#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <deque>

using namespace std;

int sided = 4;

int board[40];
int visited[40];

deque<int> communityChest({ 0, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 });
deque<int> chance({ 0, 10, 11, 24, 39, 5, -2, -2, -3, -4, -1, -1, -1, -1, -1, -1 });

int next()
{
    static long long int seed = 290797;
    seed = (seed * seed) % 50515093;

    return (int)seed;
}

int throwDice()
{
    static int doubles = 0;

    int first = next() % sided + 1;
    int second = next() % sided + 1;

    if (first == second)
        doubles++;
    else
        doubles = 0;

    if (doubles == 3)
    {
        doubles = 0;
        return -1;
    }

    return first + second;
}

int communityChestCard(int position)
{
    int a = communityChest.front();
    communityChest.pop_front();
    communityChest.push_back(a);

    position = (a >= 0) ? a : position;

    return position;
}

int chanceCard(int position)
{
    int a = chance.front();
    chance.pop_front();
    chance.push_back(a);

    if (a >= 0)
    {
        position = a;
    }

    else
    {
        if (a == -2)
        {
            if (position == 7)
                position = 15;
            else if (position == 22)
                position = 25;
            else
                position = 5;
        }

        else if (a == -3)
        {
            if (position == 7 or position == 36)
                position = 12;
            else
                position = 28;

        }
        else if (a == -4)
        {
            position -= 3;

            if (position == 33)
                position = communityChestCard(position);
        }
    }

    return position;
}

void simulate(int N)
{
    int position = 0;

    for (int i = 0; i < N; i++)
    {
        int t = throwDice();

        if (t == -1)
        {
            position = 10;
            visited[10]++;
            continue;
        }

        position += t;

        if (position >= 40)
            position %= 40;

        else if (position < 0)
            position += 40;

        if (position == 30)
        {
            position = 10;
            visited[10]++;
            continue;
        }

        else if (position == 7 or position == 22 or position == 36)
        {
            position = chanceCard(position);
        }

        else if (position == 2 or position == 17 or position == 33)
        {
            position = communityChestCard(position);
        }

        visited[position]++;
    }
}

int main()
{
    for (int i = 0; i < 40; i++)
        board[i] = i;

    auto rng = default_random_engine{};

    shuffle(communityChest.begin(), communityChest.end(), rng);

    rng = default_random_engine{};

    shuffle(chance.begin(), chance.end(), rng);

    int loop = 1000000;

    simulate(loop);

    for (int j = 0; j < 3; j++)
    {
        double mx = 0;
        int tmp_i = 0;

        for (int i = 0; i < 40; i++)
        {
            if (mx < 100.0 * visited[i] / (double)loop)
            {
                mx = 100.0 * visited[i] / (double)loop;
                tmp_i = i;
            }
        }

        visited[tmp_i] = 0;

        if (tmp_i < 10)
            cout << "0" << tmp_i;
        else
            cout << tmp_i;
    }

    cout << endl;

    return 0;
}