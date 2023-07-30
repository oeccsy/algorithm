#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    int i,j,k;
    array<int, 101> arr = {0, };

    cin >> n >> m;

    for(int iter=0; iter<m; iter++)
    {
        cin >> i >> j >> k;

        for(int target=i; target<=j; target++)
        {
            arr[target] = k;
        }
    }

    for(int iter = 1; iter<=n; iter++)
    {
        cout << arr[iter] << " ";
    }
}