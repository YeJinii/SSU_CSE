//퇴사_실버 3
#include <iostream>
#include <algorithm>

#define MN 16

using namespace std;

int T[MN];
int P[MN];
int dp[MN][MN];

int N, ans;

void dfs(int day, int price)
{

    if (day == N)
    { // dfs의 종점
        ans = max(ans, price);
        return;
    }

    if (day + T[day] <= N)
    {
        dfs(day + T[day], price + P[day]);
    }

    dfs(day + 1, price);
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> P[i];
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}