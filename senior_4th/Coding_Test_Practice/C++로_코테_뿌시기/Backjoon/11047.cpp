//동전 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(void){
    
    int N, K; cin>> N>> K;
    vector <int> money;
    int answer=0;

    for(int i=0; i<N; i++){
        int m; cin>>m;
        money.push_back(m);
    }

    sort(money.begin(), money.end(), cmp);

    for(int i=0; i<money.size(); i++){
        if(K/money[i]>0){ 
            answer+=K/money[i];
            K=K%money[i];
        }else continue;
    }

    cout<<answer;
    return 0;

}
