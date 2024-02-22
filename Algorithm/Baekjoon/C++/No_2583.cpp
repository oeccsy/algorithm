#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// (row, col)이 아닌 (x, y)를 저장
// 0 : 색칠되지 않음, 탐색하지 않음
// 1 : 색칠되지 않음, 탐색함
// 2 : 색칠됨
int paper[100][100];
queue<pair<int,int>> check_target;
vector<int> areas;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int m,n,k;

int main()
{
    cin >> m >> n >> k;

    for(int i=0; i<k; i++)
    {
        int start_x,start_y,end_x,end_y;
        cin >> start_x >> start_y >> end_x >> end_y;

        for(int i=start_x; i<end_x; i++)
        {
            for(int j=start_y; j<end_y; j++)
            {
                paper[i][j] = 2;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(paper[i][j] == 0)
            {
                int area = 1;
                paper[i][j] = 1;
                check_target.push({i,j});
                
                while(!check_target.empty())
                {
                    pair<int,int> cur = check_target.front();
                    check_target.pop();

                    for(int d=0; d<4; d++)
                    {
                        pair<int,int> next = {cur.first+dx[d], cur.second+dy[d]};

                        if(next.first < 0 || next.second <0 || next.first >= n || next.second >= m) continue;
                        if(paper[next.first][next.second] != 0) continue;

                        area++;
                        paper[next.first][next.second] = 1;
                        check_target.push(next);
                    }
                }

                areas.push_back(area);
            }
        }
    }

    sort(areas.begin(), areas.end());
    cout << areas.size() << '\n';
    for(int area : areas)
    {
        cout << area << " ";
    }

}