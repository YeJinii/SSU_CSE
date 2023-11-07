#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);

    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        ret += A[i] * B[i];
    }

    cout << ret;
}