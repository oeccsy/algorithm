#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ropes;

bool cmp(int a, int b)
{
    return a >= b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int rope_input;
        cin >> rope_input;
        
        ropes.push_back(rope_input);
    }
    
    sort(ropes.begin(), ropes.end(), cmp);

    int result = 0;
    int rope_count = 0;
    
    for(auto r : ropes)
    {
        rope_count++;
        
        if(result <= r * rope_count)
        {
            result = r * rope_count;
        }
    }
    
    cout << result;
}