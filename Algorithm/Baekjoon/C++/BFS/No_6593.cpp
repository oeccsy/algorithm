#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int l,r,c;

int main()
{
    while(true)
    {
        char building[30][30][30];
        int dist[30][30][30];
        bool visit[30][30][30];
        queue<tuple<int,int,int>> check_target;

        bool escape = false;
        
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) break;

        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                for(int k=0; k<c; k++)
                {
                    char input;
                    cin >> input;

                    building[i][j][k] = input;
                    dist[i][j][k] = 0;
                    visit[i][j][k] = false;
                    
                    if(input == 'S')
                    {
                        dist[i][j][k] = 0;
                        visit[i][j][k] = true;
                        check_target.push({i,j,k});
                    }
                }
            }
        }

        while(!check_target.empty())
        {
            int cur_x,cur_y,cur_z;
            tie(cur_x,cur_y,cur_z) = check_target.front();
            check_target.pop();

            if(building[cur_x][cur_y][cur_z] == 'E')
            {
                cout << "Escaped in " << dist[cur_x][cur_y][cur_z] << " minute(s)." << '\n';
                escape = true;
                break;
            }

            for(int idx = 0; idx<6; idx++)
            {
                int nx = cur_x + dx[idx];
                int ny = cur_y + dy[idx];
                int nz = cur_z + dz[idx];

                if(nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
                if(visit[nx][ny][nz]) continue;
                if(building[nx][ny][nz] == '#') continue;

                dist[nx][ny][nz] = dist[cur_x][cur_y][cur_z] + 1;
                visit[nx][ny][nz] = true;
                check_target.push({nx,ny,nz});
            }
        }

        if(escape == false)
        {
            cout << "Trapped!" << '\n';
        }
    }
}