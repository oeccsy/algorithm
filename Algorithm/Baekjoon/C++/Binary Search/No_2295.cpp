#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> u;
vector<int> u_two_sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int u_input;
        cin >> u_input;
        u.push_back(u_input);
    }
    
    sort(u.begin(), u.end());
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            u_two_sum.push_back(u[i] + u[j]);
        }
    }
    
    sort(u_two_sum.begin(), u_two_sum.end());
    
    int result = 0;
    
    for(int i=n-1; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            if(binary_search(u_two_sum.begin(), u_two_sum.end(), u[i]-u[j]))
            {
                result = max(result, u[i]);    
            }
        }
    }
    
    cout << result;
}