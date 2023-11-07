#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    
    int N; cin>>N;
    vector <int> v;

    while(N--){
        int n; cin>>n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}