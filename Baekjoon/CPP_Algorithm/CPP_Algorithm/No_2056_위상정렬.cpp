#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int num;
    int cost;
};

Node* nodes[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, answer = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int cost_input, adj_size, adj_num;
        
        nodes[i] = new Node();
        nodes[i]->num = i;
        
        cin >> cost_input;
        nodes[i]->cost = cost_input;

        cin >> adj_size;
        for(int j=0; j<adj_size; j++)
        {
            cin >> adj_num;

            Node* u = nodes[i];
            Node* v = nodes[adj_num];

            u->cost = max(u->cost, cost_input + v->cost);
        }

        if(answer < nodes[i]->cost) answer = nodes[i]->cost;
    }

    cout << answer;
}