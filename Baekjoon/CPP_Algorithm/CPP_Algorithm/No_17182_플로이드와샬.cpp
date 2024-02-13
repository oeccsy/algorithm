#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t[11][11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int answer = 1000000000;
    
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> t[i][j];
        }
    }
    
    for(int h=0; h<n; h++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                t[i][j] = min(t[i][j], t[i][h]+t[h][j]);
            }
        }
    }
    
    vector<int> path;
    for(int i=0; i<n; i++)
    {
        if(i==k) continue;
        path.push_back(i);
    }
    
    do
    {
        int dist = t[k][path[0]];

        for(int i=1; i<path.size(); i++)
        {
            dist += t[path[i-1]][path[i]];
        }
        
        answer = min(answer, dist);
    }
    while(next_permutation(path.begin(), path.end()));
    
    cout << answer;
}