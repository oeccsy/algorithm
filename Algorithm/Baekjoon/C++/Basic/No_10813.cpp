#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    int i,j;
    array<int, 101> arr;

    for(int iter=0; iter<101; iter++)
    {
        arr[iter] = iter;
    }

    cin >> n >> m;

    for(int iter=0; iter<m; iter++)
    {
        cin >> i >> j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int iter = 1; iter<=n; iter++)
    {
        cout << arr[iter] << " ";
    }
}