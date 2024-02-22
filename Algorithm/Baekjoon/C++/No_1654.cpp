#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int lan[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n;
    cin >> k >> n;
    
    for(int i=0; i<k; i++)
    {
        cin >> lan[i];           
    }
    
    long long st=1;
    long long en=INT_MAX;
    
    while(st < en)
    {
        long long mid = (st+en+1)/2;
        int lan_count = 0;
        //길이가 mid 일 때 lan_count를 n개 이상 만들 수 있는가?

        for(int i=0; i<k; i++)
        {
            int cur_lan = lan[i];
            lan_count += cur_lan / mid;
        }

        if(lan_count >= n)
        {
            st = mid;
        }
        else
        {
            en = mid-1;
        }
    }
    
    cout << st;
}