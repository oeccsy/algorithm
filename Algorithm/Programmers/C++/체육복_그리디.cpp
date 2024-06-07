#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int count[40] = {0,};
    
    for(int i=1; i<=n; i++)
    {
        count[i] = 1;   
    }
    
    for(int i=0; i<lost.size(); i++)
    {
        count[lost[i]]--;
    }
    
    for(int i=0; i<reserve.size(); i++)
    {
        count[reserve[i]]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(count[i] > 0)
        {
            answer++;
        }
        else if(count[i-1] > 1)
        {
            count[i-1]--;
            count[i]++;
            answer++;
        }
        else if(count[i+1] > 1)
        {
            count[i+1]--;
            count[i]++;
            answer++;
        }
    }
    
    return answer;
}