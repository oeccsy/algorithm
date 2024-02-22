#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> start_time_pq (jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> available_jobs_pq;
    
    int cur_time = 0;
    int total_time = 0;
    int job_count = jobs.size();
    
    int answer = 0;
    
    if(jobs.size() == 0) return 0;
    
    while(job_count > 0)
    {
        while(!start_time_pq.empty())
        {
            vector<int> target_job = start_time_pq.top();
            
            if(target_job[0] <= cur_time)
            {
                available_jobs_pq.push({target_job[1], target_job[0]});
                start_time_pq.pop();
            }
            else
            {
                break;
            }
        }
        
        if(available_jobs_pq.empty())
        {
            cur_time++;
            continue;
        }
        
        vector<int> cur_job = available_jobs_pq.top();
        available_jobs_pq.pop();
        
        cur_time += cur_job[0];
        total_time += cur_time - cur_job[1];
        job_count--;
    }
    
    answer = total_time / jobs.size();
    
    return answer;
}