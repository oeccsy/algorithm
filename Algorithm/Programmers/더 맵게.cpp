#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int new_food_score(int a, int b)
{
    return a + b * 2;
}

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    int greater_than_k_count = 0;
    
    for(auto it = scoville.begin(); it != scoville.end(); it++)
    {
        if(*it < K)
        {
            pq.push(*it);
        }
        else
        {
            greater_than_k_count++;
        }
    }
    
    while(pq.size() >= 2)
    {   
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        int new_food = new_food_score(a, b);
        answer++;
        
        if(new_food < K)
        {
            pq.push(new_food);
        }
        else
        {
            greater_than_k_count++;
        }
    }
    
    if(!pq.empty())
    {
        if(greater_than_k_count == 0)
        {
            answer = -1;
        }
        else
        {
            answer++;
        }
    }
        
    return answer;
}