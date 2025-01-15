#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 9> arr;
    int max;
    int max_index;

    for(int i=0; i<9; i++)
    {
        cin >> arr[i];
    }

    max = arr[0];
    max_index = 0;
    
    for(int i=1; i<9; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            max_index = i;
        }
    }

    cout << max << '\n' << max_index+1;
}