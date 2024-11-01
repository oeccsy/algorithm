#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> temp_lis;

    int a0;
    cin >> a0;
    temp_lis.push_back(a0);

    for(int i=1; i<n; i++)
    {
        int ai;
        cin >> ai;
        
        if(temp_lis.back() < ai)
        {
            temp_lis.push_back(ai);
        }
        else
        {
            *(lower_bound(temp_lis.begin(), temp_lis.end(), ai)) = ai;
        }
    }

    cout << temp_lis.size();
}