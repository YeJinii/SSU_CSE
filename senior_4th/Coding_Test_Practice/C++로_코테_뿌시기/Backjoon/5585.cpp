#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    n = 1000 - n;

    int ans=0;

    //500엔
    ans += n / 500;
    n %= 500;
    
    ans += n / 100;
    n %= 100;

    ans += n / 50;
    n %= 50;

    ans += n / 10;
    n %= 10;

    ans += n / 5;
    n %= 5;

    ans += n / 1;

    cout << ans;
}