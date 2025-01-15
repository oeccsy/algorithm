#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int h[605];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> h[i];
    }

    sort(h, h+n);

    int a, b, c, d; // a < b < c < d
    int ans = abs((h[0] + h[3]) - (h[1] + h[2]));

    for(b=1; b<n-2; b++)
    {
        for(c=b+1; c<n-1; c++)
        {
            a=b-1;
            d=c+1;

            while(true)
            {
                ans = min(ans, abs((h[a] + h[d]) - (h[b] + h[c])));

                if(h[a]+h[d] == h[b]+h[c])
                {
                    cout << 0;
                    return 0;
                }

                if(h[a]+h[d] < h[b]+h[c])
                {
                    d++;
                    if(d>=n) break;
                }
                else
                {
                    a--;
                    if(a<0) break;
                }
            }
        }
    }

    cout << ans;
}