#include <string>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

map<string, int> rCnt;
map<string, set<string>> rList;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{

    vector<int> answer;

    for (string s : report)
    {
        int blank = s.find(' ');
        string from = s.substr(0, blank);
        string to = s.substr(blank);

        if (rList[from].find(to) == rList[from].end())
        { //신고 한 적이 없다면

            rCnt[to]++;             //신고당한 횟수를 count
            rList[from].insert(to); //from이 신고한 사람을 리스트에 추가
        }
    }

    for (string s : id_list)
    {
        int ret = 0;
        for (string s1 : rList[s])
        {
            if (rCnt[s1] >= k)
                ret++;
        }
        answer.push_back(ret);
    }

    return answer;
}