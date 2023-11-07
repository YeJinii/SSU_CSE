#include <iostream>
#include <queue>

#define MN 1010

using namespace std;

int N;

bool graph[MN][MN];
bool visited[MN];

//깊이 우선 탐색
void dfs(int V)
{
    cout << V << ' ';
    visited[V] = true;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && graph[V][i])
        {
            dfs(i);
        }
        else
            continue;
    }

    return;
}

//너비 우선 탐색
void bfs(int V)
{
    queue<int> q;
    q.push(V);
    cout << V << ' ';
    visited[V] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i] && graph[v][i])
            {
                q.push(i);
                cout << i << ' ';
                visited[i] = true;
            }
        }
    }

    return;
}

int main(void)
{

    int M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    dfs(V);

    cout << "\n";

    for (int i = 0; i < MN; i++)
        visited[i] = false;

    bfs(V);

    return 0;
}