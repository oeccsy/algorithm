#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> poketmon_types;
    
    for(auto num : nums)
    {
        poketmon_types.insert(num);
    }
    
    answer = min(poketmon_types.size(), nums.size()/2);
    
    return answer;
}