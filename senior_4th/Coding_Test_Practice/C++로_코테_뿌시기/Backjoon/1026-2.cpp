#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    
    int N; cin>>N;
    vector <int> A(N);
    vector <int> B(N);
    int answer=0;

    for(int i=0; i<N; i++) cin>>A[i];
    for(int i=0; i<N; i++) cin>>B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i=0; i<N; i++){
        answer+=A[i]*B[N-i-1];
    }

    cout<<answer;
}