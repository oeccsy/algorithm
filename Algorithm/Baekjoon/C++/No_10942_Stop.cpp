#include <iostream>

using namespace std;

int nums[2001];
bool palindrome[2001][2001]; //[s][e]

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> nums[i];
    }
    

    cin >> m;

    for(int i=0; i<m; i++)
    {
        int s,e;
        cin >> s >> e;
    }
    
}