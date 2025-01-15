#include <iostream>
#include <algorithm>

using namespace std;

int seq[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s;
    cin >> n >> s;

    for(int i=0; i<n; i++)
    {
        cin >> seq[i];
    }

    int st = 0;
    int en = 0;

    int sum = 0;
    int min_len = 0;

    for(int i=0; i<n; i++)
    {
        sum += seq[i];

        if(sum >= s)
        {
            en = i;
            min_len = en + 1;
            break;
        }
    }

    if(sum < s)
    {
        cout << 0;
        return 0;
    }

    while(true)
    {
        sum -= seq[st];
        st++;

        if(sum >= s)
        {
            min_len = min(min_len, en-st+1);
        }
        else
        {
            en++;
            if(en >= n) break;

            sum += seq[en];
        }
    }

    cout << min_len;
}