#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    queue<int> window;
    int window_len_count[21];
    long long best_friends = 0;

    for(int i=0; i<=20; i++)
    {
        window_len_count[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        string name;
        cin >> name;

        int name_len = name.size();
        
        best_friends += window_len_count[name_len];

        window_len_count[name_len]++;
        window.push(name_len);

        if(window.size() > k)
        {
            window_len_count[window.front()]--;
            window.pop();
        }
    }

    cout << best_friends;
}