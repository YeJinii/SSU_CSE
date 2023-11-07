#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int prime[9999999+1];
int n;
bool visited[8];
map <int,int> m;
int MN=0;

void eratos(){
    //초기화
    for(int i=2; i<=MN; i++) prime[i]=i;
    for(int i=2; i*i<=MN; i++){
        if(prime[i]==0) continue;
        for(int j=i+i; j<=MN; j+=i){
            prime[j]=0;
        }
    }
}

void make_list(string s, int k){
    if(k==n){
        string ns="";
        for(int i=0; i<n; i++){
            if(visited[i]){
                ns+=s[i];
            }
        } 
        if(ns.length()!=0){
            m[stoi(ns)]++;
            MN = max(MN, stoi(ns));
        } 
        return ;
    }
    visited[k]=false;
    make_list(s,k+1);
    
    visited[k]=true;
    make_list(s,k+1);
}

int solution(string numbers) {
    
    int answer = 0;
    eratos();
    
    n=numbers.length();
    
    string snumbers=numbers;
    do{
        make_list(numbers,0);
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    do{
        make_list(snumbers,0);
    }while(prev_permutation(snumbers.begin(), snumbers.end()));
    
    eratos();
    
    for(auto i=m.begin(); i!=m.end(); i++)
    {
        if(i->second && prime[i->first]){
            answer++;
        }
    }    
    
    return answer;
}