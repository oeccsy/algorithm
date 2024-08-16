#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int st_count[1000005];
int en_count[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        int st, en;
        cin >> st >> en;

        st_count[st]++;
        en_count[en]++;
    }

    int a = 0;
    int b = 0;
    int a_seg_count = 0;
    int b_seg_count = 0;
    int sum = 0;

    while(true)
    {
        if(sum < k)
        {
            b_seg_count += st_count[b];
            b_seg_count -= en_count[b];
            b++;

            if(b > 1000000) break;
            
            sum += b_seg_count;
            if(sum == k)
            {
                cout << a << " " << b;
                return 0;
            }
        }
        else
        {
            a_seg_count += st_count[a];
            a_seg_count -= en_count[a];
            a++;
            
            sum -= a_seg_count;
            if(sum == k)
            {
                cout << a << " " << b;
                return 0;
            }
        }
    }

    cout << "0 0";
}