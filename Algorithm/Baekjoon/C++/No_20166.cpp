#include <iostream>
#include <unordered_map>

using namespace std;

int n, m, k;
char grid[15][15];

int dr[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[8] = {1, -1, 0, 1, -1, 0, 1, -1};

unordered_map<string, int> answer_table;
string cur_string;
int answer = 0;

void select(int r, int c, int depth)
{
    if(depth > 5) return;

    cur_string.push_back(grid[r][c]);
    answer_table[cur_string]++;

    for(int i=0; i<8; i++)
    {
        int next_r = (r + dr[i] + (n-1)) % n + 1;
        int next_c = (c + dc[i] + (m-1)) % m + 1;

        select(next_r, next_c, depth+1);
    }

    cur_string.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 타일마다 알파벳 소문자
    // n행 m열의 격자 왼쪽 위 1,1, 오른쪽 아래 n,m

    // 아무곳 시작, 모든방향 1칸 이동 가능, 지나왔던 칸 다시 방문 허용
    // 각 칸의 알파벳 이어붙여 문자열
    // 문자열 k개를 알려주면, 만들어낼 수 있는 경우의 수 구하기
    // 방문 순서가 다르면 다른 경우
    // 1행, n행 연결됨, 1열, m열 연결됨
    
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=m; c++)
        {
            select(r, c, 1);   
        }
    }

    for(int i=0; i<k; i++)
    {
        string goal;
        cin >> goal;

        cout << answer_table[goal] << '\n';
    }
}