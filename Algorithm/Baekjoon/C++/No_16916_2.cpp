#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> make_failure(string& pattern)
{
    vector<int> f(pattern.size(), 0);

    f[0] = 0;
    
    for(int i=1; i<pattern.size(); i++)
    {
        int prefix_last_index = 0 + f[i-1];
        int suffix_last_index = i;

        while(pattern[prefix_last_index] != pattern[suffix_last_index])
        {
            if(prefix_last_index-1 < 0) break;
            prefix_last_index = f[prefix_last_index-1];
        }

        if(pattern[prefix_last_index] == pattern[suffix_last_index])
        {
            f[i] = (prefix_last_index + 1);
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

    vector<int> f = make_failure(p);

    int i = 0;
    int j = 0;

    while(i < s.size() && j < p.size())
    {
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = f[j-1];
            }
        }
    }

    if(j == p.size())
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}