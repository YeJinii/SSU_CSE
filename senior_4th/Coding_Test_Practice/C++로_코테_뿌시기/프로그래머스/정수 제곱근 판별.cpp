#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    bool check=false;
    for(long long i=1; i<=n; i++){
        if(n/i==i && n%i==0) {//나누어 떨어짐도 추가로 확인해줘야함
            answer=pow(i+1,2);
            check=true;
            break;
        }
    }
    if(!check) answer=-1;
    return answer;
}