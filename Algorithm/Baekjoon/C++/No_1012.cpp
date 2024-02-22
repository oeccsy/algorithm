#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int T;
int M, N, K;
//int X, Y;

int baechoo[51][51] = { 0, };
int visit[51][51] = { 0, };

queue<pair<int, int>> Q;

int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

void BFS()
{
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dirX[i];
            int ny = cur.second + dirY[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (visit[nx][ny] || !baechoo[nx][ny]) continue;

            visit[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
}

int main()
{
    cin >> T;
    int count = 0;
    for (int i = 0; i < T; i++)
    {
        count = 0;

        cin >> M >> N >> K;

        for (int j = 0; j < K; j++)
        {
            int X, Y;
            cin >> X >> Y;
            baechoo[X][Y] = 1;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (baechoo[i][j] && !visit[i][j])
                {
                    visit[i][j] = 1;
                    Q.push({ i,j });
                    BFS();
                    count++;
                }
            }
        }

        cout << count << "\n";

        fill(&visit[0][0], &visit[50][50], 0); //배열의 index범위를 잘 확인할것
        fill(&baechoo[0][0], &baechoo[50][50], 0);
    }
}