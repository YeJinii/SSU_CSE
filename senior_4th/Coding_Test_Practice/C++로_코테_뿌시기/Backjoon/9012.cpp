//괄호_실버4
#include <iostream>
#include <string> //string 클래스 사용 시 필요 헤더
#include <vector>

using namespace std;
int main(void)
{
    int N;
    cin >> N;
    while (N--)
    {
        bool check = true; // 잘못된 문장인지 체크해주는 변수
        string s;
        cin >> s;
        vector<char> v;

        //stack 구조로 '('입력 시 push, '(' 입력시 pop
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                v.push_back('(');
            }
            else
            {
                if (v.size() == 0)
                {
                    check = false;
                    break;
                }
                else
                {
                    v.pop_back();
                }
            }
        }

        if (v.size() != 0 || !check)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}