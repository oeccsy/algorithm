#include <iostream>
#include <algorithm>

using namespace std;

int card[500005];

bool bs(int st, int en, int target)
{
    while(st < en)
    {
        int mid = (st+en)/2;

        if(card[mid] < target)
        {
            st=mid+1;
        }
        else if(target < card[mid])
        {
            en=mid;
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> card[i];
    }
    
    sort(card, card+n);
    
    cin >> m;
    
    for(int i=0; i<m; i++)
    {
        int target;
        cin >> target;
        
        int st = 0;
        int en = n;

        cout << bs(st, en, target) << " ";
    }
}