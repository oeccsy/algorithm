#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    char left_child;
    char right_child;
};

Node nodes[200];

void pre_order_travel(char parent)
{
    if(parent == '.') return;
    
    cout << parent;
    pre_order_travel(nodes[(int)parent].left_child);
    pre_order_travel(nodes[(int)parent].right_child);
}

void in_order_travel(char parent)
{
    if(parent == '.') return;
   
    in_order_travel(nodes[(int)parent].left_child);
    cout << parent;
    in_order_travel(nodes[(int)parent].right_child);
}

void post_order_travel(char parent)
{
    if(parent == '.') return;
    
    post_order_travel(nodes[(int)parent].left_child);
    post_order_travel(nodes[(int)parent].right_child);
    cout << parent;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        char node_name, left_child, right_child;
        cin >> node_name >> left_child >> right_child;
        
        nodes[(int)node_name].left_child = left_child;
        nodes[(int)node_name].right_child = right_child;
    }
    
    pre_order_travel('A');
    cout << '\n';
    in_order_travel('A');
    cout << '\n';
    post_order_travel('A');
}