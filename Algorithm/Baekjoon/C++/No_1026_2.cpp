#include <iostream>
#include <algorithm>

using namespace std;

int a[55];
int b[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n, greater<int>());
    sort(b, b + n, less<int>());

    int min_s = 0;

    for(int i=0; i<n; i++)
    {
        min_s += a[i] * b[i];    
    }

    cout << min_s;
}