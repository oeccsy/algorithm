#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int number;
    int indegree;
    bool is_sorted;
    vector<int> adj;
};

Node nodes[33000];
vector<int> sort_result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        nodes[u].adj.push_back(v);
        nodes[v].indegree++;
    }

    while (sort_result.size() != n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (nodes[i].indegree != 0) continue;
            if (nodes[i].is_sorted) continue;

            sort_result.push_back(i);
            nodes[i].is_sorted = true;

            for (auto it = nodes[i].adj.begin(); it != nodes[i].adj.end(); ++it)
            {
                nodes[*it].indegree--;
            }
        }
    }
    
    for (auto it = sort_result.begin(); it != sort_result.end(); ++it)
    {
        cout << *it << ' ';
    }
}
