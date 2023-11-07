//시험 감독
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    long long int N, B, C, cnt;
    cin >> N;

    vector<long long int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    cin >> B >> C;

    for (int i = 0; i < N; i++)
    {

        A[i] = A[i] - B;

        //감독할 학생 수가 더이상 없으면 0으로 마킹
        if (A[i] <= 0)
            A[i] = 0;
    }

    cnt = N; //총감독관수 더하기

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += A[i];

    /****빼기로 접근했더니 시간초과 남****/
    // while (sum != 0)
    // {
    //     for (int i = 0; i < N; i++)
    //     {
    //         if (A[i] == 0)
    //             continue;
    //         else
    //         {
    //             A[i] -= C;
    //             cnt++;

    //             if (A[i] <= 0)
    //                 A[i] = 0;
    //         }
    //     }

    //     //sum을 0으로 초기화 해주지 않고
    //     //이 값에 누적으로 배열 값을 더해서 무한루프가 돌았었음
    //     sum = 0;
    //     for (int j = 0; j < N; j++)
    //         sum += A[j];
    // }

    /****나누기로 접근****/
    for (int i = 0; i < N; i++)
    {
        if (A[i] == 0)
            continue;

        cnt += A[i] / C;
        if (A[i] % C != 0)
            cnt++;
    }

    cout << cnt;

    return 0;
}