#include <iostream>
#include <algorithm>

using namespace std;

struct Object
{
    int weight;
    int value;
};

int d[105][100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
    {
        int w, v;
        cin >> w >> v;
        
        Object new_object({w, v});

        for(int j=0; j<=k; j++)
        {
            if(j >= w)
            {
                d[i][j] = max(d[i-1][j], v + d[i-1][j-w]);
            }
            else
            {
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[n][k];
}