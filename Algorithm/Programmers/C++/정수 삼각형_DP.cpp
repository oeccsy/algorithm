#include <string>
#include <vector>

using namespace std;

int d[505][505]; //d[i][j] : index i에서 triangle[i][j]를 선택했을 때 최댓값

int solution(vector<vector<int>> triangle)
{    
    int answer = 0;
    
    d[0][0] = triangle[0][0];
    
    for(int i=1; i<triangle.size(); i++)
    {   
        for(int j=0; j<triangle[i].size(); j++)
        {
            if(j == 0)
            {
                d[i][j] = d[i-1][j] + triangle[i][j];
            }
            else
            {
                d[i][j] = max(d[i-1][j-1] + triangle[i][j], d[i-1][j] + triangle[i][j]);
            }
        }
    }
    
    int max_i = triangle.size()-1;
    int max_j = triangle[max_i].size()-1;
    
    for(int j=0; j<=max_j; j++)
    {
        if(answer < d[max_i][j]) answer = d[max_i][j];
    }
    
    return answer;
}