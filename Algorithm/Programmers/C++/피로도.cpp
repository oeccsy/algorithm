#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_visit[8] = {false, };
int answer = -1;

void dfs(int status, int depth, vector<vector<int>>& dungeons)
{
    for(int i=0; i<dungeons.size(); i++)
    {
        if(is_visit[i]) continue;
        
        int req = dungeons[i][0];
        int cost = dungeons[i][1];
        
        if(status >= req)
        {
            is_visit[i] = true;
            depth++;
            
            if(depth > answer) answer = depth;
            dfs(status-cost, depth, dungeons);
            
            is_visit[i] = false;
            depth--;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(k, 0, dungeons);
    
    return answer;
}