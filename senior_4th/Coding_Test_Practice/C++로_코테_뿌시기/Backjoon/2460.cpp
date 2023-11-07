//지능형 기차 2_브론즈3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int main(void)
{
    int cur = 0;
    for (int i = 0; i < 10; i++)
    {
        int out_n, in_n;
        cin >> out_n >> in_n;
        cur = cur - out_n + in_n;
        v.push_back(cur);
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - 1];
}