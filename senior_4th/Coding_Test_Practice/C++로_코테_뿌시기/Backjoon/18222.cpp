//투에-모스 문자열_실버 2
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;

void findAnswer(string x)
{

    if (x.length() >= N)
    {
        cout << x.substr(N - 1, 1);
        return;
    }

    string x2 = "";
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '1')
            x2 += '0';
        else
            x2 += '1';
    }

    x += x2;

    findAnswer(x);
}

int main(void)
{
    cin >> N;
    findAnswer("0");
    return 0;
}