#include <iostream>

using namespace std;

int main(void){
    
    int N; cin>>N;
    
    int answer=0;
    while(N>=0){
        if(N%5==0){
            answer+=N/5;
            cout<<answer;
            return 0;
        }
        else{
            N-=3;
            answer++;
        }
    }
    if(N==0) cout<<answer;
    else cout<<-1;

    return 0;
}