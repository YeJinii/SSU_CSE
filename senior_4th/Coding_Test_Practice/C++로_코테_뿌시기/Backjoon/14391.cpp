//종이 조각
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N,M,ret=0;

int paper[5][5];
bool check[5][5];

void dfs(int num, int sum){
    int x=num/N;
    int y=num%M;
    if(num>=N*M) {
        ret = max(ret,sum);
        return;
    }
    if(check[x][y]) dfs(num+1, sum); // 이미 방문한 노드라면
    else{
        int nx, ny, val;
        val=paper[x][y];
        check[x][y]=true;
        dfs(num+1, sum+val);
        check[x][y]=false;

        //아래로
        for(int i=0; i<N-x; i++){
            nx=x+i;
            ny=y;
            val *= 10;
            val += paper[nx][ny];
            for(int j=1; j<=i; j++) check[x+i][ny] = false;
        }
        val = paper[]
    }
}
int main(void){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&paper[i][j]);
        }
    }
    dfs(0,0);
}