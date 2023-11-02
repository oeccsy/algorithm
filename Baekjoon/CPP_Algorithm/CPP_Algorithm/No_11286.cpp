#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int abs_heap[100005];
int rear = 1;

bool cmp(int index_a, int index_b)
{
    int abs_a = abs(abs_heap[index_a]);
    int abs_b = abs(abs_heap[index_b]);
    
    if(abs_a != abs_b)
        return abs_a < abs_b;
    else
        return abs_heap[index_a] <= abs_heap[index_b];
}

void swap_node(int index_a, int index_b)
{
    int temp = abs_heap[index_a];
    abs_heap[index_a] = abs_heap[index_b];
    abs_heap[index_b] = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int cmd;
        cin >> cmd;
        
        if(cmd != 0)
        {
            int new_node_index = rear;
            rear++;
            
            abs_heap[new_node_index] = cmd;
            
            while(true)
            {
                int parent_index = new_node_index / 2;

                if(parent_index < 1) break;
                
                if(cmp(parent_index, new_node_index))
                {
                    break;
                }
                else
                {
                    swap_node(parent_index, new_node_index);
                    new_node_index = parent_index;
                }
            }
        }
        else
        {
            if(rear == 1)
            {
                cout << 0 << '\n';
                continue;
            }
            
            cout << abs_heap[1] << '\n';
            abs_heap[1] = abs_heap[rear-1];
            rear--;
            
            int check_target = 1;
            
            while(true)
            {
                int parent = check_target;
                int left_child = 2*check_target;
                int right_child = 2*check_target+1;

                if(left_child >= rear || right_child >= rear) break;
                
                if(cmp(parent, left_child) && cmp(parent, right_child))
                {
                    break;
                }
                else if(cmp(left_child, right_child))
                {
                    swap_node(parent, left_child);
                    check_target = left_child;
                }
                else
                {
                    swap_node(parent, right_child);
                    check_target = right_child;
                }
            }
        }
    }
    
}