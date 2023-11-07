#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    
    int N; cin>>N;
    vector <int> v;

    while(N--){
    
        string s; cin>>s;
    
        if(!s.compare("push")){
            int n; cin>>n;
            v.push_back(n);
        }
        else if(!s.compare("pop")){
            if(v.size()==0){
                cout<<-1<<'\n';
                continue;
            }
            int cur = v.size()-1;
            cout<<v[cur]<<'\n';
            v.erase(v.begin()+cur);
        }
        else if(!s.compare("size")){
            cout<<v.size()<<'\n';
        }
        else if(!s.compare("empty")){
            if(v.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }
        else if(!s.compare("top")){
            if(v.size()==0){
                cout<<-1<<'\n';
                continue;
            }
            cout<<v[v.size()-1]<<'\n';
        }
    }
}