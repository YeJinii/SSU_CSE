#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool check[26];

int main(void)
{
    int ans = 0;
    int n;
    cin >> n;

    while (n--)
    {
        //check 배열 초기화
        for (int i = 0; i < 26; i++)
            check[i] = false;

        string s;
        cin >> s;
        char cur = s[0];
        bool stop = false;

        for (int i = 0; i < s.length(); i++)
        {

            if (!check[s[i] - 97])
            {
                check[s[i] - 97] = true;
                cur = s[i];
            }
            else
            { //이미 마킹이 되어있다면
                //전 알파벳과 동일한지 (연속적인지) 확인
                if (s[i] == cur)
                    continue;
                else
                {
                    stop = true;
                    break;
                }
            }
        }

        if (stop)
        {
            continue;
        }
        else
        {
            ans++;
        }
    }

    cout << ans << endl;
}