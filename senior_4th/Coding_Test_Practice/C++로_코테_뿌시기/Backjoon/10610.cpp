#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

int main(void)
{
    string s;
    cin >> s;

    sort(s.begin(), s.end(), cmp);

    int sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
    }

    if ((sum % 3 != 0) || (s[s.size() - 1] != '0'))
    {
        cout << -1;
        return 0;
    }

    cout << s;
    return 0;
}