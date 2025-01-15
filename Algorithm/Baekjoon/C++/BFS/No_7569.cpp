#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int box[100][100][100];
int day[100][100][100];
int m, n, h;

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

queue<tuple<int,int,int>> red_tomato;
int result = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> h;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                int input;
                cin >> input;
                box[i][j][k] = input;
                day[i][j][k] = 0;

                if(input == 1) red_tomato.push({i,j,k});
            }
        }
    }

    while(!red_tomato.empty())
    {
        tuple<int,int,int> cur = red_tomato.front();
        red_tomato.pop();

        int cur_X,cur_Y,cur_Z;
        tie(cur_X,cur_Y,cur_Z) = cur;
        int cur_day = day[cur_X][cur_Y][cur_Z];

        for(int i=0; i<6; i++)
        {
            int next_X,next_Y,next_Z;
            tie(next_X,next_Y,next_Z) = cur;
            next_X += dx[i];
            next_Y += dy[i];
            next_Z += dz[i];

            if(next_X < 0 || next_Y < 0 || next_Z < 0 || next_X >= h || next_Y >= n || next_Z >= m) continue;
            if(box[next_X][next_Y][next_Z] != 0) continue;

            box[next_X][next_Y][next_Z] = 1;
            day[next_X][next_Y][next_Z] = cur_day + 1;
            red_tomato.push({next_X,next_Y,next_Z});
        }
    }

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                if(box[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
    
                if(result < day[i][j][k])
                {
                    result = day[i][j][k];
                }
            }
        }
    }

    cout << result;
}