#include <iostream>
#include <algorithm>

using namespace std;

int x[1000005];
int x_copy[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        x_copy[i] = x[i];
    }
      
    sort(x_copy, x_copy+n);
    int en = unique(x_copy, x_copy+n) - x_copy;
    
    for(int i=0; i<n; i++)
    {
        cout << lower_bound(x_copy, x_copy+en, x[i]) - x_copy << " ";
    }
}