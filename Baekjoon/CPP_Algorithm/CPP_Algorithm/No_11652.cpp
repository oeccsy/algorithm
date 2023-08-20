#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int arr_count[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    sort(arr, arr + n);

    int cur = 0;
    int cur_index = 0;
    int result_index = 0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] != cur)
        {
            cur = arr[i];
            cur_index = i;
            arr_count[cur_index]++;

            if(arr_count[result_index] < arr_count[cur_index])
            {
                result_index = cur_index;
            }
        }
        else
        {
            arr_count[cur_index]++;

            if(arr_count[result_index] < arr_count[cur_index])
            {
                result_index = cur_index;
            }
        }
    }

    cout << arr[result_index];
}
