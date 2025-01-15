#include <iostream>
#include <queue>

using namespace std;

int n,k;
int dist[100001];
queue<int> check_target;

void BFS(int start)
{
    check_target.push(start);

    while(!check_target.empty())
    {
        int cur_pos = check_target.front();
        check_target.pop();

        int cur_pos_dist = dist[cur_pos];
        
        if(cur_pos == k)
        {
            cout << cur_pos_dist;
            break;
        }
        
        if(cur_pos-1 >= 0 && cur_pos-1 != n && dist[cur_pos-1] == 0)
        {
            dist[cur_pos-1] = cur_pos_dist+1;
            check_target.push(cur_pos-1);    
        }
        if(cur_pos+1 <= 100000 && cur_pos+1 != n && dist[cur_pos+1] == 0)
        {
            dist[cur_pos+1] = cur_pos_dist+1;
            check_target.push(cur_pos+1);
        }
        if(2*cur_pos <= 100000 && 2*cur_pos != n && dist[2*cur_pos] == 0)
        {
            dist[2*cur_pos] = cur_pos_dist+1;
            check_target.push(2*cur_pos);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    BFS(n);
}