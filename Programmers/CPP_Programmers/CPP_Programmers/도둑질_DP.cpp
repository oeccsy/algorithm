#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long d1[1000000][2]; //d[i][j] i번째 집을 j{안털/털}었을 때 최댓값
long long d2[1000000][2];
int solution(vector<int> money) 
{
    int answer = 0;
    
    // 첫 번째 집을 털지 않은 경우
    d1[0][0] = 0;
    
    for(int i=1; i<money.size(); i++)
    {
        d1[i][0] = max(d1[i-1][0], d1[i-1][1]);
        d1[i][1] = d1[i-1][0] + money[i];
    }
    
    int max_d1 = max(d1[money.size()-1][0], d1[money.size()-1][1]);
    
    // 첫 번째 집을 턴 경우
    d2[0][1] = money[0];
    
    for(int i=1; i<money.size(); i++)
    {
        d2[i][0] = max(d2[i-1][0], d2[i-1][1]);
        d2[i][1] = d2[i-1][0] + money[i];
    }

    int max_d2 = d2[money.size()-1][0];
    
    answer = max(max_d1, max_d2);
    return answer;
}