#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int weight;
    int node_a;
    int node_b;
};

int parents[10005];
Edge edges[100005];

int Find(int x)
{
    if(parents[x] == x)
        return x;
    else
        return Find(parents[x]);
}

void Union(int x, int y)
{
    int x_root = Find(x);
    int y_root = Find(y);

    parents[y_root] = x_root;
}

bool Cmp(const Edge& e1, const Edge& e2){
    if(e1.weight <= e2.weight) return true;
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int v, e;
    cin >> v >> e;
    
    for(int i=0; i<e; i++)
    {
        int node_a, node_b, weight;
        cin >> node_a >> node_b >> weight;

        parents[node_a] = node_a;
        parents[node_b] = node_b;
        
        Edge newEdge = {weight, node_a, node_b};
        edges[i] = (newEdge);
    }

    sort(edges, edges+e, Cmp);

    int edge_select_count = 0;
    int weight_sum = 0;

    for(int i=0; i<e; i++)
    {
        Edge curEdge = edges[i];

        if(Find(curEdge.node_a) != Find(curEdge.node_b))
        {
            Union(curEdge.node_a, curEdge.node_b);
            weight_sum += curEdge.weight;
            edge_select_count++;
        }

        if(edge_select_count == v-1) break;
    }

    cout << weight_sum;
}
