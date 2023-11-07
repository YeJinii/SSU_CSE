//평범한 배낭 _ 골드 5

#include <iostream>
#include <algorithm>
#include <cstdio>

#define max_N 101 // define 문 뒤에는 세미콜론을 붙이지 말자 ㅋㅋㅋㅋ

using namespace std;

int weight[max_N];
int value[max_N];
int dp[max_N][101010];

int main(void)
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j >= weight[i])
            { // 넣을 아이템의 무게가 j(베낭에 들어갈수 있는 무게)보다 작거나 같으면
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else
            { //아얘 넣을 무게가 아님
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    //결과값 출력
    cout << dp[N][K];

    return 0;
}