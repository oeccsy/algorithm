#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 마지막 셔틀의 마지막 자리가 비어있는 시간
// 마지막 셔틀의 마지막 자리에 탑승하는 크루의 시간 -1분


string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    sort(timetable.begin(), timetable.end());
    
    int cur_time = 900;
    int ans_time = 0;
    auto next_it = timetable.begin();
    
    for(int i=0; i<n; i++)
    {
        cout << i << endl;
        for(int j=1; j<=m; j++)
        {
            if(next_it == timetable.end())
            {
                // 남아있는 크루 없음
                ans_time = cur_time;
                cout << "end : " << cur_time << endl;
                break;
            }
                
            int next_crew_hour = stoi(next_it->substr(0, 2));
            int next_crew_min = stoi(next_it->substr(3, 2));
            int next_crew_time = next_crew_hour * 100 + next_crew_min;
            
            if(next_crew_time <= cur_time)
            {
                // 탑승할 크루 있음
                if(j == m) // 만약 마지막 자리면, 1분 전에 도착해야함
                {
                    int temp_time = next_crew_time - 1;
                    if(temp_time < 0) temp_time += 60;
                    if(temp_time % 100 >= 60) temp_time -= 40;
                    
                    ans_time = temp_time;
                    cout << "Temp : " << temp_time << endl;
                }
                
                next_it++;
            }
            else
            {
                // 셔틀의 자리가 비어있음
                cout << cur_time << endl;
                ans_time = cur_time;
                break;
            }
        }
        
        int cur_min = cur_time % 100;
        cur_min += t;

        if(cur_min >= 60)
        {
            cur_time += 100;
            cur_min -= 60;
        }
        
        cur_time -= cur_time % 100;
        cur_time += cur_min;
    }
    
    if(ans_time / 100 < 10) answer += "0";
    answer += to_string(ans_time / 100);
    answer += ":";
    if(ans_time % 100 < 10) answer += "0";
    answer += to_string(ans_time % 100);
    
    return answer;
}