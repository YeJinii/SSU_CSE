//����� �賶 _ ��� 5

#include <iostream>
#include <algorithm>
#include <cstdio>

#define max_N 101 // define �� �ڿ��� �����ݷ��� ������ ���� ��������

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
            { // ���� �������� ���԰� j(������ ���� �ִ� ����)���� �۰ų� ������
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else
            { //�ƾ� ���� ���԰� �ƴ�
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    //����� ���
    cout << dp[N][K];

    return 0;
}