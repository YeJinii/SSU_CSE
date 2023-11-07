//우리집엔 도서관이 있어_ 실버 3
#include <iostream>
#include <vector>
#include <algorithm>
#define MN 300001

using namespace std;

int arr[MN];

int main(void)
{
    int N;
    cin >> N;
    int max_idx = -1;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if (arr[i] == N)
            max_idx = i;
    }

    int cnt = 1;

    for (int i = max_idx - 1; i > 0; i--)
    {
        if (arr[i] == arr[max_idx] - 1)
        {
            cnt++;
            max_idx = i;
        }
    }

    cout << N - cnt;
}