#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1; i<=yellow; i++){
        if(yellow%i==0){
            int h=i;
            int w=yellow/i;
            if(h*2+w*2+4==brown){
                answer.push_back(w+2);
                answer.push_back(h+2);
                return answer;
            }
        }
    }
    return answer;
}