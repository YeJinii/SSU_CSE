//뒤집기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check = true; //1일때 , false: 0일 때 

int main(void){
    
    string s; cin>>s;
    int one=0;
    int zero=0;

    if(s[0]=='0'){
        zero++;
        check = false;
    } 
    else one++;

    for(int i=1; i<s.length(); i++){
        if(check){//1이었는데
            if(s[i]!='1'){//0으로 변경 시
                zero++;
                check=false;
            }
            else continue; //계속 1
        }
        else{//0이었는데
            if(s[i]!='0'){//1로 변경 시
                one++;
                check=true;
            }
            else continue;
        }
    }

    cout<<min(one,zero);
    return 0;

}