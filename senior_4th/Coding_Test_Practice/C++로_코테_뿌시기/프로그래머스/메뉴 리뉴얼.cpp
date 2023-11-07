#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map <string,int> m[10+1];
int max_cnt[10+1];

void comb(string s, int cnt, string ns){//부분 조합을 생성하는 함수
    if(cnt==s.length()){
        int len=ns.length();
        if(len>1){
            m[len][ns]++;
            if(max_cnt[len]<m[len][ns]) max_cnt[len]=m[len][ns];
        }
        return ;
    }
    
    comb(s,cnt+1,ns+s[cnt]);
    comb(s,cnt+1,ns);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto i: orders){
        sort(i.begin(), i.end());
        comb(i, 0, "");
    }
    
    for(auto i:course){
        for(auto iter:m[i]){
            if(iter.second>1 && iter.second==max_cnt[i]){
                answer.push_back(iter.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}