#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
    int start_time;
    int end_time;
};

bool cmp(Meeting* a, Meeting* b)
{
    if(a->end_time != b->end_time)
        return a->end_time < b->end_time;
    else
        return a->start_time < b->start_time;
}

vector<Meeting*> meetings;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int s, e;
        cin >> s >> e;
        
        Meeting* new_meeting = new Meeting{s, e};
        meetings.push_back(new_meeting);
    }
    
    sort(meetings.begin(), meetings.end(), cmp);
    
    int result = 0;
    int schedule_end = -1;
    
    for(auto it=meetings.begin(); it!=meetings.end(); ++it)
    {
        Meeting* cur_meeting = *it;
        
        if(schedule_end <= cur_meeting->start_time)
        {
            schedule_end = cur_meeting->end_time;
            result++;
        }
    }
    
    cout << result;
}