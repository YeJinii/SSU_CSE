#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    
    int N; cin>>N;
    long long int answer = 0;

    vector <long long int> dist(N-1);
    vector <long long int> price(N);

    for(int i=0; i<N-1; i++){
        cin>>dist[i];
    }

    for(int i=0; i<N; i++){
        cin>>price[i];
    }

    long long int min_price = price[0];

    for(int i=0; i<N-1; i++){
        answer+=min_price*dist[i];
        if(min_price>price[i+1]) min_price = price[i+1];
    }

    cout<<answer;
    return 0;
    
}