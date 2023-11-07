//ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    
    int N; cin>>N;
    vector <int> v(N);
    int answer=0;
    
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    
    sort(v.begin(), v.end());

    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<' ';
    // }cout<<endl;

    for(int i=1; i<v.size(); i++){
        v[i]=v[i-1]+v[i];
    }

    for(int i=0; i<v.size(); i++){
        answer+=v[i];
    }

    cout<<answer;

    return 0;
}