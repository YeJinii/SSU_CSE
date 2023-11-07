//벽 부수고 이동하기_
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define MN 1010

using namespace std;

int N, M;
int m[MN][MN];
int visited[MN][MN][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct Info
{
    int x;
    int y;
    int w;
};

int main(void)
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            m[i][j] = s[j - 1] - '0';
        }
    }

    queue<Info> q;
    Info info = {0, 0, 0};
    q.push(info);
    visited[0][0][0] = true;

    while (!q.empty())
    {

        Info tmp = q.front();
        q.pop();
        int x = tmp.x;
        int y = tmp.y;
        int w = tmp.w;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx > 0 && ny > 0 && nx <= N && ny <= M)
            {
                if (!m[nx][ny] && !visited[nx][ny][w])
                {
                    visited[nx][ny][w] = visited[x][y][w] + 1;
                    q.push({nx, ny, w});
                }
                else if (!visited[nx][ny][w] && w == 0)
                {
                }
            }
        }
    }

    // 배열 출력 형식
    // for (int i = 0; i <= N; i++)
    // {
    //     for (int j = 0; j <= M; j++)
    //     {
    //         cout << m[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}