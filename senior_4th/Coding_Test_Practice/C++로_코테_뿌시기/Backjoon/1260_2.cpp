#include <iostream>
#include <queue>
#include <algorithm>

#define MN 1001

using namespace std;

int N, M, V;
bool graph[MN][MN];
bool visited[MN];

void dfs(int v){
    cout<<v<<' ';
    visited[v]=true;
    for(int i=1; i<=N; i++){
        if(graph[v][i]&&!visited[i]) dfs(i);
    }
}

void bfs(int v){
    
    visited[v]=true;
    cout<<v<<' ';
    
    queue <int> q;
    q.push(v);

    while(!q.empty()){
        
        int cur=q.front(); 
        q.pop();

        for(int i=1; i<=N; i++){

            if(graph[cur][i]&&!visited[i]){
                visited[i]=true;
                q.push(i);
                cout<<i<<' ';
            }

        }

    }

}


int main(void){

    cin >> N >> M >> V;
    
    for(int i=0; i<M; i++){
        int u,v; cin>>u>>v;
        //양방향이자나 바보야...
        graph[u][v]=true;
        graph[v][u]=true;
    }

    dfs(V); cout<<'\n';

    for(int i=0; i<MN; i++) visited[i]=false;
    
    bfs(V);

    return 0;

}