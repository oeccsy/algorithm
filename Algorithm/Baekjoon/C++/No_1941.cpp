#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Princess
{
    int r;
    int c;
    char group;
};

Princess seven_princesses[7];
char classroom[5][5];
bool is_used[5][5];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = 0;

bool is_linked(Princess princesses[])
{
    int link_count = 0;
    bool is_visit[5][5];

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            is_visit[i][j] = false;
        }
    }
    
    stack<pair<int,int>> dfs_stack;
    pair<int,int> start = {princesses[0].r, princesses[0].c};

    dfs_stack.push(start);
    is_visit[start.first][start.second] = true;
    link_count++;

    while(!dfs_stack.empty())
    {
        pair<int,int> cur = dfs_stack.top();
        dfs_stack.pop();

        for(int i=0; i<4; i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
            if(!is_used[nr][nc]) continue;
            if(is_visit[nr][nc]) continue;

            dfs_stack.push({nr, nc});
            is_visit[nr][nc] = true;
            link_count++;
        }
    }

    return (link_count == 7);
}

void select_princess(int index)
{
    if(index == 7)
    {
        int s_count = 0;

        for(int i=0; i<7; i++)
        {
            if(seven_princesses[i].group == 'S') s_count++;
        }

        if(s_count >=4 && is_linked(seven_princesses)) answer++;
        
        return;
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(is_used[i][j]) continue;
            if(index != 0 && 10 * i + j <= 10 * seven_princesses[index-1].r + seven_princesses[index-1].c) continue;

            is_used[i][j] = true;
            seven_princesses[index] = {i, j, classroom[i][j]};
            select_princess(index+1);
            is_used[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 5x5
    // 규칙
    // 7명의 학생들로 구성
    // 가로/세로로 인접
    // 7명 중 이다솜파 학생이 4명이상 포함

    for(int i=0; i<5; i++)
    {
        cin >> classroom[i];
    }

    select_princess(0);

    cout << answer;
}