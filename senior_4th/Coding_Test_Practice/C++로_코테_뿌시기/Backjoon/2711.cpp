//오타맨 고창영_브론즈 2
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int ota = 0;
        string bs = "", as = ""; //before_string, after_string
        cin >> ota >> bs;

        for (int i = 0; i < bs.length(); i++)
        {
            if (i == (ota - 1))
                continue;
            else
                as += bs[i];
        }

        cout << as << endl;
    }
}