//외판원 순회 2
#include <iostream>
#include <vector>
#include <algorithm>

#define MN 11
#define INF 987654321

using namespace std;

int W[MN][MN];
vector<int> v;

int calc(vector<int> &v)
{
    int ret = 0;

    for (int i = 1; i < v.size(); i++)
    {
        if (W[v[i - 1]][v[i]] == 0)
            return INF;
        ret += W[v[i - 1]][v[i]];
    }

    if (W[v[v.size() - 1]][v[0]] == 0)
        return INF;

    return ret + W[v[v.size() - 1]][v[0]];
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> W[i][j];
        }
    }

    int ans = INF;
    do
    {
        ans = min(ans, calc(v));
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;
    return 0;
}