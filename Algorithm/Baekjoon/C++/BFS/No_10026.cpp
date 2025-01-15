#include <iostream>
#include <queue>

using namespace std;

int n;
char picture_A[100][100]; 
char picture_B[100][100];

int area_count_a;
int area_count_b;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS_A(char color, int row, int col)
{
    queue<pair<int,int>> q;
    q.push({row, col});
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            pair<int,int> next = {cur.first+dx[i], cur.second+dy[i]};

            if(next.first < 0 || next.first >= 100 || next.second < 0 || next.second >= 100) continue;
            if(picture_A[next.first][next.second] != color) continue;

            picture_A[next.first][next.second] = 'N';
            q.push(next); 
        }
    }
}

void BFS_B(char color, int row, int col)
{
    queue<pair<int,int>> q;
    q.push({row, col});
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            pair<int,int> next = {cur.first+dx[i], cur.second+dy[i]};

            if(next.first < 0 || next.first >= 100 || next.second < 0 || next.second >= 100) continue;
            if(picture_B[next.first][next.second] != color) continue;

            picture_B[next.first][next.second] = 'N';
            q.push(next); 
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            char input;
            cin >> input;
            picture_A[i][j] = input;

            if(input == 'G') input = 'R';
            picture_B[i][j] = input;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(picture_A[i][j] != 'N')
            {
                BFS_A(picture_A[i][j], i, j);
                area_count_a++;
            }

            if(picture_B[i][j] != 'N')
            {
                BFS_B(picture_B[i][j], i, j);
                area_count_b++;
            }
        }
    }

    cout << area_count_a << " " << area_count_b;
}