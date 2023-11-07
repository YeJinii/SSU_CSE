#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(void)
{

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int w;
        cin >> w;
        v.push_back(w);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        int n;

        if (N - i == 1)
            continue;
        n = v[i] * (N - i);
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    cout << v[v.size() - 1];
}