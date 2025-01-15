#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int a_input;
        cin >> a_input;
        a.push_back(a_input);
    }
    
    for(int i=0; i<n; i++)
    {
        int b_input;
        cin >> b_input;
        b.push_back(b_input);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int result = 0;
    
    for(int i=0; i<n; i++)
    {
        result += a[n-1-i] * b[i];    
    }
    
    cout << result;
}