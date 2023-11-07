#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.size()>1&&pq.top()<K){
        answer++;
        int first=pq.top(); pq.pop();
        int second=pq.top(); pq.pop();
        int make=first+second*2;
        pq.push(make);
    }
    if(pq.top()<K) return -1;
    return answer;
}