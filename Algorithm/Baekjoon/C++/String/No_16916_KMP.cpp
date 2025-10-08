#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> failure(string& str)
{
    vector<int> f(str.size());
    int j=0;

    for(int i=1; i<str.size(); i++)
    {
        while(j>0 && str[i] != str[j])
        {
            j = f[j-1];
        }
        
        if(str[i] == str[j])
        {
            f[i] = j + 1;
            j++;
        }
    }

    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;

    vector<int> f = failure(p);
    int j=0;

    for(int i=0; i<s.size(); i++)
    {
        while(j>0 && s[i] != p[j])
        {
            j = f[j-1];
        }

        if(s[i] == p[j]) j++;

        if(j == p.size())
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}