#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> v(9);

int main(void)
{

    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
    }

    int vsum = accumulate(v.begin(), v.end(), 0);

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (vsum - v[i] - v[j] == 100)
            {
                v[i] = -1;
                v[j] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (v[i] == -1)
            continue;
        else
            cout << v[i] << '\n';
    }

    return 0;
}