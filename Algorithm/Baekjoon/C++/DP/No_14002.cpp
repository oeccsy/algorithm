#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001][2];
// [i][0] : 처음으로 포함하는 원소가 i일때 최대 길이
// [i][1] : 최대 길이일 때 다음 원소의 index

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        d[i][0] = 1;
    }

    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; i+j<=n; j++)
        {
            if(a[i] < a[i+j] && d[i][0] < d[i+j][0] + 1)
            {
                d[i][0] = d[i+j][0]+1;
                d[i][1] = i+j;
            }
        }
    }

    int max = 0;
    int index = 0;
    
    for(int i=1; i<=n; i++)
    {
        if(max < d[i][0])
        {
            max = d[i][0];
            index = i;
        }   
    }
    
    cout << max << '\n';
    
    while(index > 0)
    {
        cout << a[index] << " ";
        index = d[index][1];
    }
}