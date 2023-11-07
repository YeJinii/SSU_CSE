//카잉 달력
#include <iostream>
using namespace std;
int main(void){

    int T; cin >> T;

    while(T--){
        
        bool check=false;
        int M, N, x, y; cin>> M >> N >> x >> y;
        x--; y--;
        for(int i=x; i<M*N; i+=M){
            if(i%N==y){
                check=true; 
                cout<<i+1<<'\n';
                break;
            }
        }

        if(!check){
            cout<<-1<<'\n';
        }

    }
    return 0;
}