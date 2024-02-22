#include <string>
#include <vector>
#include <iostream>

using namespace std;

int d[101][101] = {0,}; // {i, j} 까지 올 수 있는 최단 경로의 수
bool is_puddle[101][101] = {false, };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0; i<puddles.size(); i++)
    {
        vector<int> pos = puddles[i];
        is_puddle[pos[0]][pos[1]] = true;
    }
    
    if(!is_puddle[1][2]) d[1][2] = 1;
    if(!is_puddle[2][1]) d[2][1] = 1;
    
    for(int sum=4; sum<=m+n; sum++)
    {
        for(int x=0; x<=sum; x++)
        {
            int y=sum-x;
            if(x < 1 || y < 1 || x > m || y > n) continue;
            
            if(is_puddle[x][y])
            {
                d[x][y] = 0;
            }
            else
            {
                d[x][y] = (d[x-1][y] + d[x][y-1]) % 1000000007;
            }
        }
    }
    
    return d[m][n];
}