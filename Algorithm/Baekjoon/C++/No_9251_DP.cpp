#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int d[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    int s1_length = s1.length();
    int s2_length = s2.length();

    for(int i=1; i<=s1_length; i++)
    {
      for(int j=1; j<=s2_length; j++)
      {
        if(s1[i-1] == s2[j-1])
        {
          d[i][j] = d[i-1][j-1] + 1;
        }
        else
        {
          d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
      }
    }

    cout << d[s1_length][s2_length];
}