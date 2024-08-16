#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n);

    int st = 0;
    int en = 0;
    int min_sub = 0;

    for(int i=0; i<n; i++)
    {
        if(a[i] - a[0] >= m)
        {
            en = i;
            min_sub = a[i] - a[0];
            break;
        }
    }

    while(true)
    {
        st++;
        if(st > en) break;

        if(a[en] - a[st] >= m)
        {
            min_sub = min(min_sub, a[en] - a[st]);
            continue;
        }
        
        en++;
        if(en >= n) break;

        if(a[en] - a[st] >= m)
        {
            min_sub = min(min_sub, a[en] - a[st]);
            continue;
        }
    }

    cout << min_sub;
}