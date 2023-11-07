//피보나치 수 5
#include <iostream>
using namespace std;
int F(int N)
{
    if (N == 1)
        return 1;
    else if (N == 0)
        return 0;
    else
        return F(N - 1) + F(N - 2);
}
int main(void)
{
    int N;
    cin >> N;
    cout << F(N);
}