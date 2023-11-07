#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(long long a, long long b){return a>b;}
long long solution(long long n) {
    long long answer = 0;
    string s=to_string(n); 
    vector <char> v;
    for(long long i=0; i<s.length(); i++) v.push_back(s[i]);
    sort(v.begin(), v.end(), cmp);
    
    s="";
    for(long long i=0; i<v.size(); i++) s+=v[i];
    
    answer=stol(s); //stoi 가 아닌 stol 사용해야함
    
    return answer;
}