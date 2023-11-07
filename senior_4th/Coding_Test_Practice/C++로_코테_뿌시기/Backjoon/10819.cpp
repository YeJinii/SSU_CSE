//차이를 최대로
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calc(vector<int> &v)
{
    int ret = 0;
    for (int i = 1; i < v.size(); i++)
    {
        ret += abs(v[i - 1] - v[i]); //문제를 잘 읽자 예진아 ..
    }
    return ret;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int ret = 0;

    do
    {
        int sum = calc(v);

        ret = max(ret, sum);

    } while (next_permutation(v.begin(), v.end()));

    cout << ret;
}