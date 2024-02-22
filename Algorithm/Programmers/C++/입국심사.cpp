#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long min_time = 1;
    long long max_time = (long long)times[times.size()-1] * n;
    
    long long left = min_time;
    long long right = max_time;
    long long mid;
    
    while(true)
    {
        long long people = 0;
        
        mid = (left + right) / 2;

        for(auto time : times)
        {
            people += mid / time;
        }
        
        if(people >= n)
        {
            // 시간 안에 심사 가능, 시간을 더 줄일 수 있는지 확인 필요함
            answer = mid;
            right = mid - 1;
        }
        else
        {
            // 시간 안에 n명 심사 불가능, 시간이 더 필요함
            left = mid + 1;
        }
        
        if(left > right) break;
    }
    
    return answer;
}