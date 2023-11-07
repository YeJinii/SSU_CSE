#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char a, char b){
    return a>b;
}

string solution(string s) {
    string answer = "";
    
    vector <char> v(s.length());
    
    for(int i=0; i<s.length(); i++){
        v[i]=s[i];
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++){
        answer+=v[i];
    }
    
    return answer;
}