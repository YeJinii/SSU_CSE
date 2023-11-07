#include <iostream>
using namespace std;

int main(void){
    int T; cin>>T;
    while(T--){
        int H, W, N; cin>>H>>W>>N;
        int count=1;
        bool check_print=false;
        for(int i=1; i<=W; i++){
            for(int j=100; j<=H*100; j+=100){
                if(count==N){
                    cout<<j+i<<'\n';
                    check_print = true;
                    break;
                }
                count++;
            }
            if(check_print) break;
        }
    }
}