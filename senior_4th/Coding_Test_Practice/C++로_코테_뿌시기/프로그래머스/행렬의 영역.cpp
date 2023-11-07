#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, cnt=0;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
bool visited[10][10];

void dfs(int x, int y, int ** matrix){

    visited[x][y]=true;

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<N){
            if(!visited[nx][ny]&&matrix[nx][ny]){
                dfs(nx, ny,matrix);
                num++;
            }
        }

    }
}

void solution(int sizeOfMatrix, int ** matrix){
    N=sizeOfMatrix;
    vector <int> v;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]&&matrix[i][j]){
                num=1;
                dfs(i,j,matrix);
                v.push_back(num);
                cnt++;
            }
            else continue;
        }
    }

    cout<<cnt<<'\n';
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) cout<<v[i]<<' ';

}
