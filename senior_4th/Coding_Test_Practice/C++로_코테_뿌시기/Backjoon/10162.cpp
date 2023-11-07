//전자레인지_브론즈 4
#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin >> n;

    int a = n / 300;
    n %= 300;

    int b = n / 60;
    n %= 60;

    int c = n / 10;
    n %= 10;

    if (n != 0)
        cout << -1;
    else
        cout << a << ' ' << b << ' ' << c;
}