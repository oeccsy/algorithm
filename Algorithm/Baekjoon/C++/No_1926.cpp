#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n, m;

int picture_count = 0;
int picture_maxsize = 0;
int picture[502][502];

// 0 : 그림 x
// 1 : 확인하지 않은 그림
// 2 : 확인한 그림

queue<pair<int, int>> check_target;

void BFS(pair<int, int> start_pos)
{
    check_target.push(start_pos);
    picture[start_pos.first][start_pos.second] = 2;
    int picture_size = 1;
    
    while(!check_target.empty())
    {
        int row = check_target.front().first;
        int col = check_target.front().second;
        
        check_target.pop();

        if(row + 1 < n && picture[row+1][col] == 1)
        {
            picture[row+1][col] = 2;
            picture_size++;

            check_target.push({row+1, col});
        }
        if(row - 1 >= 0 && picture[row-1][col] == 1)
        {
            picture[row-1][col] = 2;
            picture_size++;

            check_target.push({row-1, col});
        }
        if(col + 1 < m && picture[row][col+1] == 1)
        {
            picture[row][col+1] = 2;
            picture_size++;

            check_target.push({row, col+1});
        }
        if(col - 1 >= 0 && picture[row][col-1] == 1)
        {
            picture[row][col-1] = 2;
            picture_size++;

            check_target.push({row, col-1});
        }
    }

    if(picture_size > picture_maxsize)
    {
        picture_maxsize = picture_size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int input;
            cin >> input;
            picture[i][j] = input;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(picture[i][j] == 1)
            {
                picture_count++;
                BFS(make_pair(i,j));
            }
        }
    }

    cout << picture_count << '\n';
    cout << picture_maxsize;
}