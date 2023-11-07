//거스름돈
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int money[6]={500, 100, 50, 10, 5, 1};

int main(void){
    
    int N; cin>>N;
    int M = 1000-N;
    int answer=0;

    for(int i=0; i<6; i++){
        if(M/money[i]>0){
            answer+=M/money[i];
            M=M%money[i];
        }
    }

    cout<<answer;
    return 0;

}