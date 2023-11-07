#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {

        int n;
        cin >> n;

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            int s, m;
            cin >> s >> m;
            v.push_back({s, m});
        }

        sort(v.begin(), v.end());

        int cutline = v[0].second;
        int cnt = 1;

        for (int i = 1; i < n; i++)
        {
            if (cutline > v[i].second)
            {
                cnt++;
                cutline = v[i].second;
            }
        }

        cout << cnt << endl;
    }
}