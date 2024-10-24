#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture
{
    int s = 0;
    int t = 0;

    Lecture(int s, int t) : s(s), t(t) {}
};

bool cmp_by_s(const Lecture& a, const Lecture& b)
{
    if(a.s != b.s)
    {
        return a.s < b.s;
    }
    else
    {
        return a.t < b.t;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수업 : Si에 시작 Ti에 종료
    // 수업 N개
    // 최소의 강의실 사용

    // Ti == Sj이면 수업 바로 시작 가능

    // 강의실 추가 여부 -> 남은 강의중 가장 일찍 시작하는 강의를 가장 일찍 비는 강의에 넣을 수 있는가?

    vector<Lecture> lectures;
    priority_queue<int, vector<int>, greater<int>> earliest_room_time;

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int s, t;
        cin >> s >> t;

        lectures.emplace_back(s, t);
    }

    sort(lectures.begin(), lectures.end(), cmp_by_s);
    earliest_room_time.push(0);

    for(const auto& lecture : lectures)
    { 
        if(earliest_room_time.top() <= lecture.s) earliest_room_time.pop();
        
        earliest_room_time.push(lecture.t);
    }

    cout << earliest_room_time.size();
}