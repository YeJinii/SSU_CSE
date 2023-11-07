#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    string answer = "";
    int wordcnt=1;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            wordcnt=1;
            answer+=' ';
            continue;
        }
        if(wordcnt%2){
            answer+=toupper(s[i]);
            wordcnt++;
        }
        else{
            answer+=tolower(s[i]);
            wordcnt++;
        }
    }
    
    return answer;
}