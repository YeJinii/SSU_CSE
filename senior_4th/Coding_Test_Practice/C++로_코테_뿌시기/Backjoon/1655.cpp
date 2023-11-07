//가운데를 말해요_골드 2
#include <iostream>
#include <queue>
#include <vector>
#include <functional> //greater, less

using namespace std;

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (max_pq.size() == min_pq.size())
        { //둘이 size가 같으면 최대힙에 추가
            max_pq.push(n);
        }
        else
        {
            min_pq.push(n);
        }

        if (!max_pq.empty() && !min_pq.empty() && (max_pq.top() > min_pq.top()))
        {
            //최대합의 top이 최소합의 top보다 크면 교체
            int tmp = max_pq.top();
            max_pq.pop();
            max_pq.push(min_pq.top());
            min_pq.pop();
            min_pq.push(tmp);
        }

        cout << max_pq.top() << "\n";
    }
}