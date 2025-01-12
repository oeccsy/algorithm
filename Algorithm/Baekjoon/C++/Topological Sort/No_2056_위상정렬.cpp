#include <iostream>
#include <vector>

using namespace std;

int costs[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, answer = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int cost, adj_size, adj_num;
        cin >> cost;
        costs[i] = cost;

        cin >> adj_size;
        for(int j=0; j<adj_size; j++)
        {
            cin >> adj_num;
            costs[i] = max(costs[i], cost + costs[adj_num]);
        }

        if(answer < costs[i]) answer = costs[i];
    }

    cout << answer;
}