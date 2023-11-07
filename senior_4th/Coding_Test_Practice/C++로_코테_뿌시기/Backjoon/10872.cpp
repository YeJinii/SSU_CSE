//팩토리얼
#include <iostream>

using namespace std;

long long int fac(int cur_num, long long int ret)
{
    if (cur_num == 0)
        return ret;
    ret *= cur_num;
    return fac(cur_num - 1, ret);
    
}

int main(void)
{
    int N;
    cin >> N;
    cout << fac(N, 1);
}