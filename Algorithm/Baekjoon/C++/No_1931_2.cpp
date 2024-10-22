#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
    int start_time;
    int end_time;

    Meeting(int start_time, int end_time) : start_time(start_time), end_time(end_time) {}
};

bool cmp_by_end_time(const Meeting& a, const Meeting& b)
{
    if(a.end_time != b.end_time)
    {
        return a.end_time < b.end_time;
    }
    else
    {
        return a.start_time < b.start_time;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<Meeting> meetings;

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int start_input, end_input;
        cin >> start_input >> end_input;

        meetings.emplace_back(start_input, end_input);
    }

    sort(meetings.begin(), meetings.end(), cmp_by_end_time);

    int meeting_room_end_time = 0;
    int count = 0;

    for(const auto& cur_meeting : meetings)
    {
        if(meeting_room_end_time <= cur_meeting.start_time)
        {
            meeting_room_end_time = cur_meeting.end_time;
            count++;
        }
    }

    cout << count;
}