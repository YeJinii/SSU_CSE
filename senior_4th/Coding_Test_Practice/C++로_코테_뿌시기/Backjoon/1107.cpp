#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define INIT 100
#define INF 999999

using namespace std;

bool broken[10];

int cal_num_size(int num){
    string snum = to_string(num);
    return snum.size();
}

bool isPossible(int num){
    string snum=to_string(num);
    for(int i=0; i<snum.size(); i++){
        //문자형이기 때문에 숫자로 변환헤서 계산해야함....-> 이거 때문에 몇 분 날림
        if(broken[snum[i]-'0']){ //고장나있으면 
            return false; //불가능
        }
    }
    return true; //가능
}

int main(void){

    int goal; cin >> goal;
    
    int n; cin >> n;

    //고장난 버튼은 broken 배열 true 표시
    for(int i=0; i<n; i++){ int b; cin>>b; broken[b]=true; }

    int only_pm_btn = abs(goal-INIT);
    int with_num_btn = INF;
    
    for(int i=0; i<INF; i++){
        if(isPossible(i)){//버튼 눌릴 수 있으면
            
            with_num_btn = min(with_num_btn, cal_num_size(i)+abs(i-goal));
            
        }
    }

    cout<<min(only_pm_btn, with_num_btn);

}