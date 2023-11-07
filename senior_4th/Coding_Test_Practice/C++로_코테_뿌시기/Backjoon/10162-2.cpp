//전자레인지
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t[3] = {300, 60, 10};
int answer[3];

int main(void){
    int T; cin>>T;
    for(int i=0; i<3; i++){
        answer[i]=T/t[i];
        T = T%t[i];
    }
    if(T>0) cout<<-1;
    else{
        for(int i=0; i<3; i++){
            cout<<answer[i]<<' ';
        }
    }
}