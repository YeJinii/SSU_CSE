#include <iostream>

using namespace std;

int main(void)
{

    int N, F;
    cin >> N >> F;

    int ans = N / F;

    cout << ans * F << ' ' << (ans + 1) * F;

    return 0;
}