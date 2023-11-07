//대표값_브론즈2
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> h;
int average = 0;

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        h[n]++;
        average += n;
    }

    // //map 자료구조 접근시 아래와 같은 방식 사용
    // for (auto &item : h)
    // {
    //     cout << item.first << " " << item.second << endl;
    // }

    int mode = 0;
    int num = 0;
    for (auto &item : h)
    {
        if (num < item.second)
        {
            mode = item.first;
            num = item.second;
        }
    }

    cout << average / 10 << endl;
    cout << mode << endl;
}