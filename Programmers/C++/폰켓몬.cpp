#include <vector>
using namespace std;

int monster[200000] = {0, };

int solution(vector<int> nums)
{
    int answer = 0;
    
    for(int i = 0; i< nums.size(); i++) {
        if(monster[nums[i]] == 0)
            answer++;
        monster[nums[i]] = 1;
    }
    
    if(answer > nums.size()/2)
        answer = nums.size()/2;
    return answer;
}