#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct node
{
    int i;
    int j;
    int w;

    bool operator<(const node& other) const
    {
        return w > other.w;
    }
};

const int N = 80;
int A[N][N];
bool visited[N * N];

priority_queue <node> q;

void visit(int i, int j, int w)
{
    if (i < 0 or i >= N or j < 0 or j >= N or visited[N * i + j])
        return;

    q.push({ i, j, w + A[i][j] });
    visited[N * i + j] = true;
}

int dijkstra()
{
    q.push({ 0, 0, A[0][0] });

    node n;

    while (!q.empty())
    {
        n = q.top();

        if (n.i == N - 1 and n.j == N - 1)
            break;

        visit(n.i + 1, n.j, n.w);
        visit(n.i, n.j - 1, n.w);
        visit(n.i, n.j + 1, n.w);
        visit(n.i - 1, n.j, n.w);

        q.pop();
    }

    return n.w;
}

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

    cout << dijkstra() << endl;

    return 0;
}