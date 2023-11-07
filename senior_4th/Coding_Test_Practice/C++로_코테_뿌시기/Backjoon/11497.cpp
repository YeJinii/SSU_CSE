//통나무 건너뛰기
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(void){
    int T; cin>>T;
    while(T--){
        
        int N; cin>>N;
        vector <int> v(N);
        
        for(int i=0; i<N; i++){
            cin>>v[i];
        }
        
        sort(v.begin(), v.end(), cmp);

        deque <int> answer;
        bool flag=true;
        for(int i=0; i<v.size(); i++){
            if(flag){
                answer.push_back(v[i]);
                flag=false;
            }else{
                answer.push_front(v[i]);
                flag=true;
            }
        }

        //뒤에 맨 앞에 원소 추가
        answer.push_back(answer[0]);

        int ret=0;
        for(int i=1; i<answer.size(); i++){
            if(ret<abs(answer[i]-answer[i-1])){
                ret = abs(answer[i]-answer[i-1]);
            }
        }

        cout<<ret<<endl;

    }

}