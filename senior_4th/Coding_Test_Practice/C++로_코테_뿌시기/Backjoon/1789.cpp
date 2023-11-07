#include <iostream>
using namespace std;
int main(void)
{
    long long int n;
    cin >> n;
    int count = 1;
    long long int sum = 0;
    while (1)
    {
        sum += count;
        if (sum > n)
        {
            count--;
            break;
        }
        count++;
    }

    cout << count;
}