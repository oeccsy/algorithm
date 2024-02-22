#include <algorithm>
#include <iostream>

using namespace std;

int n,m;
int nums[8];
bool is_used[8];

int selected[8];


void Count(int index)
{
    if(index == m)
    {
        for(int i=0; i<m; i++)
        {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(is_used[i]) continue;
        
        selected[index] = nums[i];
        is_used[i] = true; 
        Count(index+1);
        is_used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        nums[i] = input;
    }

    sort(nums, nums+n);

    Count(0);
}