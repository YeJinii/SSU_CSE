#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp_n;

bool cmp(string a, string b){
    if(a[cmp_n]==b[cmp_n]) return a<b;
    else return a[cmp_n]<b[cmp_n];
}

vector<string> solution(vector<string> strings, int n) {
    
    vector<string> answer;
    cmp_n=n;
    
    sort(strings.begin(), strings.end(), cmp);
    answer=strings;
    
    return answer;

}