#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int total_fare[201][201];
int share_fare;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    
    for(auto fare : fares)
    {
        total_fare[fare[0]][fare[1]] = fare[2];
        total_fare[fare[1]][fare[0]] = fare[2];
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i == j || total_fare[i][k] == 0 || total_fare[k][j] == 0) continue;
                
                if(total_fare[i][j] == 0)
                {
                    total_fare[i][j] = total_fare[i][k] + total_fare[k][j];
                }
                else
                {
                    total_fare[i][j] = min(total_fare[i][j], total_fare[i][k] + total_fare[k][j]);    
                }
            }
        }
    }
    
    share_fare = total_fare[s][a] + total_fare[s][b];

    for(int k=1; k<=n; k++)
    {
        if(k != s && total_fare[s][k] == 0) continue;
        if(k != a && total_fare[k][a] == 0) continue;
        if(k != b && total_fare[k][b] == 0) continue;
        share_fare = min(share_fare, total_fare[s][k] + total_fare[k][a] + total_fare[k][b]);
    }
    
    return share_fare;
}