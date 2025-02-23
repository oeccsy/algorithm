#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 1. 대기실은 5개, 크기는 5x5
// 2. 맨해튼 거리가 2 이하로 앉지 말기
// 3. 앉아있는 자리 사이가 파티션으로 막혀 있을 경우 허용

// 응시자 P, 빈 테이블 O, 파티션 X

// 궁금한 것 = 대기실이 주어지면, 잘 지켜지고 있는가? 1 : 0

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool is_valid(int row, int col, vector<string>& place)
{
    int dist[5][5] = {0};
    bool is_visit[5][5] = {false};
    
    queue<pair<int,int>> bfs_queue;
    dist[row][col] = 0;
    is_visit[row][col] = true;
    bfs_queue.push({row, col});
    
    while(!bfs_queue.empty())
    {
        int cur_row = bfs_queue.front().first;
        int cur_col = bfs_queue.front().second;
        bfs_queue.pop();
        
        for(int i=0; i<4; i++)
        {
            int next_row = cur_row + dr[i];
            int next_col = cur_col + dc[i];
            
            if(is_visit[next_row][next_col]) continue;
            if(next_row < 0 || next_col < 0 || next_row >= 5 || next_col >= 5) continue;
            if(place[next_row][next_col] == 'X') continue;
            
            dist[next_row][next_col] = dist[cur_row][cur_col] + 1;
            is_visit[next_row][next_col] = true;
            bfs_queue.push({next_row, next_col});
            
            if(place[next_row][next_col] == 'P' && dist[next_row][next_col] <= 2) return false;
            if(dist[cur_row][cur_col] > 2) return true;
        }
    }
    
    return true;
}


vector<int> solution(vector<vector<string>> places)
{    
    vector<int> answer;
    
    for(int i=0; i<places.size(); i++)
    {
        vector<pair<int, int>> people_indices;
        
        for(int j=0; j<places[i].size(); j++)
        {
            for(int k=0; k<places[i][j].size(); k++)
            {
                if(places[i][j][k] == 'P') people_indices.push_back({j, k});
            }
        }
        
        if(people_indices.empty())
        {
            answer.push_back(1);
            continue;
        }
        
        bool is_all_valid = true;
        
        for(int j=0; j<people_indices.size(); j++)
        {
            auto index = people_indices[j];
            
            if(!is_valid(index.first, index.second, places[i]))
            {
                is_all_valid = false;
                break;
            }
        }
        
        if(is_all_valid)
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    
    return answer;
}