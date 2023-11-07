#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int min_num=arr[0]; int min_idx=0;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<min_num){
            min_num=arr[i];
            min_idx=i;
        }
    }
    
    arr.erase(arr.begin()+min_idx);
    if(arr.empty()) arr.push_back(-1);
    answer=arr;
    
    return answer;
}