#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    for(int i=0; i<seoul.size(); i++){
        if(!seoul[i].compare("Kim")){ 
            answer.append(to_string(i));
            break;
        }
    }
    answer+="에 있다";
    return answer;
}