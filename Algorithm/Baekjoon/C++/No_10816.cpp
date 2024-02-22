#include <iostream>
#include <algorithm>

using namespace std;

int a[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    
    sort(a, a+n);
    
    cin >> m;
    
    for(int i=0; i<m; i++)
    {
        int target;
        cin >> target;
        
        cout << upper_bound(a, a+n, target) - lower_bound(a, a+n, target) << " ";
    }
}