#include <iostream>
#include <stack>

using namespace std;

stack<int> coins;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int cost = k;
    int result = 0;
    
    for(int i=0; i<n; i++)
    {
        int coin;
        cin >> coin;
        
        coins.push(coin);
    }
    
    while(cost > 0)
    {
        int cur_coin = coins.top();
        coins.pop();
        
        while(cur_coin <= cost)
        {
            cost -= cur_coin;
            result++;
        }       
    }
    
    cout << result;
}