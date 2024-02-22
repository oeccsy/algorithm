#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    // 가장 높은 거리의 최솟값이 될 수 있는지 확인할 범위
    int left = 0;
    int right = distance;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
     
        int delete_count = 0;
        int prev_pos = 0;
        
        for(int i=0; i<rocks.size(); i++)
        {
            int cur_pos = rocks[i];
            
            if(cur_pos - prev_pos < mid)
            {
                // 바위를 제거해야 하는 상황. 거리 비교는 prev_pos를 유지해야 한다. 
                delete_count++;
            }
            else
            {
                // 바위를 제거하지 않아도 되는 상황. 거리 비교 대상이 바뀐다.
                prev_pos = cur_pos;
            }
        }
        
        if(distance - prev_pos < mid) delete_count++;
        
        if(delete_count <= n)
        {
            answer = mid;
            left = mid + 1;
        }
        else if(delete_count > n)
        {
            right = mid - 1;
        }
    }
    
    return answer;
}