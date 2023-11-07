//슈퍼 마리오_브론즈 1
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        sum += n;

        if (sum > 100)
        {
            if (abs(sum - 100) > abs((sum - n) - 100))
            { //더하기 전이 더 가까운 수이면
                cout << sum - n;
                return 0;
            }
            else if (abs(sum - 100) > abs((sum - n) - 100))
            {
                cout << sum;
                return 0;
            }
            else
            { //가까운 수가 2개이면
                cout << max(sum, sum - n);
                return 0;
            }
        }
    }

    cout << sum;

    return 0;
}