#include <iostream>
#include <algorithm>

using namespace std;

string arr[100000];

void Reverse(string& s)
{
    while(s.back() == '0')
    {
        s.pop_back();
    }
    
    reverse(s.begin(), s.end());
}

bool Compare(string& a, string& b)
{
    if(a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        Reverse(input);
        
        arr[i] = input;
    }
    
    sort(arr, arr + n, Compare);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << '\n';
    }
}
