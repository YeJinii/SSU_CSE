//연산자 끼워넣기 (2)
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000

using namespace std;

vector <int> num;

int max_ret=-INF;
int min_ret=INF;

void dfs(int idx, int sum, int P, int Mi, int Mu, int D){
    if(idx==num.size()){
        max_ret=max(max_ret,sum);
        min_ret=min(min_ret,sum);
        return ;
    }

    if(P>0){
        dfs(idx+1, sum+num[idx], P-1, Mi, Mu, D);
    }
    if(Mi>0){
        dfs(idx+1, sum-num[idx], P, Mi-1, Mu, D);
    }
    if(Mu>0){
        dfs(idx+1, sum*num[idx], P, Mi, Mu-1, D);
    }
    if(D>0){
        dfs(idx+1, sum/num[idx], P, Mi, Mu, D-1);
    }

}

int main(void){
    
    int N; cin>>N;
    
    for(int i=0; i<N; i++){
        int n; cin>>n;
        num.push_back(n);
    }

    int P,Mi,Mu,D;
    cin>>P>>Mi>>Mu>>D;

    dfs(1, num[0], P, Mi, Mu, D);

    cout<<max_ret<<'\n'<<min_ret<<'\n';

}