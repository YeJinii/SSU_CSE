#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

int main(void)
{

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        { //나누어 떨어지므로 리스트에 추가
            answer.push_back(i);
        }
    }

    if (answer.size() < K)
    {
        cout << 0;
        return 0;
    }

    cout << answer[K - 1];

    return 0;
}