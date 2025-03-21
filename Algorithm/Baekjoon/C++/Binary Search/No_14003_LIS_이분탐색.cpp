#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> a;
vector<int> indices;

vector<int> pre_lis;
int max_len = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a0;
    cin >> a0;
    a.push_back(a0);
    indices.push_back(0);
    pre_lis.push_back(a0);
    max_len++;
    
    for(int i=1; i<n; i++)
    {
        int ai;
        cin >> ai;
        a.push_back(ai);

        if(pre_lis.back() < ai)
        {
            pre_lis.push_back(ai);
            max_len++;
            
            indices.push_back(pre_lis.size()-1);
        }
        else
        {
            auto it = lower_bound(pre_lis.begin(), pre_lis.end(), ai);
            *it = ai;
            indices.push_back(it - pre_lis.begin());
        }
    }

    cout << max_len << '\n';

    int target_index = max_len-1;
    stack<int> lis;

    for(int i=a.size()-1; i>=0; i--)
    {
        if(indices[i] == target_index)
        {
            lis.push(a[i]);
            target_index--;
        }
    }

    while(!lis.empty())
    {
        cout << lis.top() << " ";
        lis.pop();
    }
}