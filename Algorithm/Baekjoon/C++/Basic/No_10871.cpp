#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    array<int, 10000> arr;

    cin >> n >> x;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] < x)
         cout << arr[i] << " ";
    }

    
    
}