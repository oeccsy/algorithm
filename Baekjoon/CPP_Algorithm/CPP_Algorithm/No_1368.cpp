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

struct Node
{
    int parent;
};

int w[305];
int parents[305];
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
    if(e1.weight < e2.weight) return true;
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int v = n;
    int e = 0;
    
    v++;
    for(int i=0; i<n; i++)
    {
        int w_input;
        cin >> w_input;
        Edge newEdge = {w_input, n, i};
        edges[e] = newEdge;
        e++;
    }

    for(int i=0; i<v; i++)
    {
        parents[i] = i;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int p_input;
            cin >> p_input;
            
            if(i == j) continue;
            
            Edge newEdge = {p_input, i, j};
            edges[e] = newEdge;
            e++;
        }
    }
    
    sort(edges, edges+e, Cmp);
    
    int result = 0;
    int count = 0;
    
    for(int i=0; i<e; i++)
    {
        Edge curEdge = edges[i];
        
        if(Find(curEdge.node_a) != Find(curEdge.node_b))
        {
            Union(curEdge.node_a, curEdge.node_b);
            result += curEdge.weight;
            count++;
        }
        
        if(count == n) break;
    }
    
    cout << result;
}
