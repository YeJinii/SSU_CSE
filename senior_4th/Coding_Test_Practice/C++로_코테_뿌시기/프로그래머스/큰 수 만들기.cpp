#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.length()-k;
    stack<char> s;
    
    for(int i=0; i<number.length(); i++){
        char cur = number.at(i);
        while(!s.empty() && k>0){
            char top=s.top();
            if(top<cur){//전에 있던 값이 더 작으므로
                s.pop();
                k--;
            }
            else break;
        }
        s.push(cur);
    }
    
    while(s.size() != size) s.pop();
    
    while(!s.empty()){
        answer+=s.top();
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}