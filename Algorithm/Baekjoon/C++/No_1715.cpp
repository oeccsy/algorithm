#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum = 0;
    int n;
    
    cin >> n;
   
    for(int i=0; i<n; i++)
    {
        int card;
        cin >> card;
        pq.push(card);
    }
    
    while(pq.size() >= 2)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        sum += a + b;
        pq.push(a+b);
    }
    
    cout << sum;
}
