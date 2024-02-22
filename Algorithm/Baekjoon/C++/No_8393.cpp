#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int total = 0;
    
    cin >> n;
    
    for(int i=1; i<=n; i++)
    {
        total += i;
    }
    
    cout << total;
}