#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        int len1, len2, len3;
        cin >> len1 >> len2 >> len3;

        if(!(len1 || len2 || len3)) return 0;
        
        int max_len = max({len1, len2, len3});
        
        int squared_sum = 0;
        if(len1 < max_len) squared_sum += len1 * len1;
        if(len2 < max_len) squared_sum += len2 * len2;
        if(len3 < max_len) squared_sum += len3 * len3;

        if(max_len * max_len == squared_sum)
        {
            cout << "right" << '\n';
        }
        else
        {
            cout << "wrong" << '\n';
        }
    }
}