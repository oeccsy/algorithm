#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
int floor_dist[1000001];
bool visit[1000001];

queue<int> check_target;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> f >> s >> g >> u >> d;

    floor_dist[s] = 0;
    visit[s] = true;
    check_target.push(s);

    while(!check_target.empty())
    {
        int cur = check_target.front();
        check_target.pop();

        if(cur == g)
        {
            cout << floor_dist[cur];
            return 0;
        }

        int next_u = cur + u;
        if(next_u <= f && visit[next_u]==false)
        {
            floor_dist[next_u] = floor_dist[cur] + 1;
            visit[next_u] = true;
            check_target.push(next_u);
        }

        int next_d = cur - d;
        if(next_d > 0 && visit[next_d]==false)
        {
            floor_dist[next_d] = floor_dist[cur] + 1;
            visit[next_d] = true;
            check_target.push(next_d);
        }
    }

    cout << "use the stairs";
}