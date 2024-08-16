#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prime_nums;

void init_prime_nums(int n)
{
    bool is_composite[n+5] = {false, };

    for(int i=2; i*i<=n; i++)
    {
        if(is_composite[i]) continue;
        
        for(int j=i+i; j<=n; j+=i)
        {
            is_composite[j] = true;
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(is_composite[i]) continue;
        prime_nums.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    init_prime_nums(n);

    int ans = 0;
    int sum = 0;

    int st = 0;
    int en = 0;

    for(int i=0; i<prime_nums.size(); i++)
    {
        sum += prime_nums[i];

        if(sum >= n)
        {
            en = i;
            if(sum == n) ans++;
            break;
        }
    }

    while(true)
    {
        if(sum >= n)
        {
            sum -= prime_nums[st];
            st++;
        }
        else
        {
            en++;
            if(en >= prime_nums.size()) break;
            sum += prime_nums[en];
        }

        if(sum == n)ans++;
    }

    cout << ans;
}