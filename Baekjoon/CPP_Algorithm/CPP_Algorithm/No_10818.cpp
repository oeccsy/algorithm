#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    array<int, 1000000> arr = {0, };

    int min, max;

    cin >> n;

    for(int  i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    min = arr[0];
    max = arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    cout << min << " " << max;
    
}