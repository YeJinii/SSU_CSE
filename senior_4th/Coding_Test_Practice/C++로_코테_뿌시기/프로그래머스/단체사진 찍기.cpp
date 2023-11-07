#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    string kakao_friends="ACFJMNRT";
    sort(kakao_friends.begin(), kakao_friends.end());
    
    do{
        bool check=true;
        for(int i=0; i<n; i++){//조건이 맞는지 체크
            char f1=data[i][0];
            char f2=data[i][2];
            char cal=data[i][3];
            int num=(int)data[i][4]-'0';
            
            int f1_idx=-1; int f2_idx=-1;
            
            int diff = kakao_friends.find(f1)-kakao_friends.find(f2); // 여기가 시간초과가 나서 안됐던거임!
            
            if(cal=='='){
                if(abs(diff)!=num+1) {
                    check=false;
                    break;
                }
            }else if(cal=='<'){
                if(abs(diff)>=num+1){
                    check=false;
                    break;
                }
            }else{//'>'
                if(abs(diff)<=num+1){
                    check=false;
                    break;
                }
            }
        }
        if(check){//조건에 만족하면
            //cout<<kakao_friends<<endl;
            answer++;
        }
    }while(next_permutation(kakao_friends.begin(), kakao_friends.end()));
    
    return answer;
}