#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    
    int N, M, J; cin>>N>>M>>J;
    int answer=0;

    vector <int> v(J);

    for(int i=0; i<J; i++){
        cin>>v[i];
    }

    int start = 1;
    int end = start+M-1;

    int before = 1;
    for(int i=0; i<v.size(); i++){
        
        if(v[i]>end){
            int move = v[i]-end;
            answer+=move;
            start+=move;
            end+=move;
        }else if(v[i]<start){
            int move = v[i]-start;
            answer-=move;
            start+=move;
            end+=move;
        }else continue;
        
    }

    cout<<answer;

    

}