#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    
    for(int i=4; i<11; i++)
    {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    
    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int n;
        cin >> n;

        cout << d[n] << '\n';
    }
}
