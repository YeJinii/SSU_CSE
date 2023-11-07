//스타트링크
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int visited[1010101];

int main(void){
    int answer = INF;

    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
    
    queue <pair<int,int>> q;
    q.push({S,0});
    visited[S]=true;

    while(!q.empty()){
        
        int cur=q.front().first;
        int btn=q.front().second;

        q.pop();
        
        if(cur==G){
            answer=min(answer, btn);
            continue;
        }

        if(cur+U<=F&&!visited[cur+U]){
            q.push({cur+U, btn+1});
            visited[cur+U]=true;
        }

        if(1<=cur-D&&!visited[cur-D]){
            q.push({cur-D, btn+1});
            visited[cur-D]=true;
        }
    }

    if(answer!=INF){
        cout<<answer<<'\n';
    }
    else cout<<"use the stairs"<<'\n';
}