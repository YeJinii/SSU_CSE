#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(string d) {
    int answer = 0;
    int num=0;

    vector<int>v;
    
    for(int i=0; i<d.length(); i++){
        if(isdigit(d[i])){//숫자면
            num*=10;
            num+=(int)d[i]-'0';
        }
        else{//문자이면
            if(d[i]=='S'){
                v.push_back(num);
                num=0;
            }
            else if(d[i]=='D'){
                v.push_back(pow(num,2));
                num=0;
            }
            else if(d[i]=='T'){
                v.push_back(pow(num,3));
                num=0;
            }
            else if(d[i]=='*'){
                if(v.size()==1){//스타상이 첫번째 기회에서 나올 경우
                    v[0]=v[0]*2;
                }
                else{
                    int cur=v.size()-1;
                    v[cur]*=2;
                    v[cur-1]*=2;
                }
            }
            else if(d[i]=='#'){
                v[v.size()-1]*=-1;
            }
            
        }
    }
    
    for(auto i:v) answer+=i;
    return answer;
}