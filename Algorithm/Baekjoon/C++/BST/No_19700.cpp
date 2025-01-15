#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct Student
{
    int h;
    int k;

    bool operator<(const Student& other) const
    {
        if(h != other.h) return h > other.h;
        else return k < other.k;
    }
};

Student students[500005];
multiset<int> team; // 현재원을 의미, 현재원 t -> k값이 t부터 들어 올 수 없는 팀

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 새로운 강의
    // 수강생 n명을 팀으로 나누려고 함
    // i번째 수강생의 팀에서 자신보다 키가 큰 사람이 ki명 이상이면 안됨
    // 최소 몇 개의 팀을 만들어야 할까?

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> students[i].h >> students[i].k;
    }

    sort(students, students + n);

    team.insert(1);

    for(int i=1; i<n; i++)
    {
        // 키 큰 순 -> 현재원이 k보다 작은 가장 큰 팀에 합류
        auto it = team.lower_bound(students[i].k); 
        
        if(it == team.begin())
        {
            team.insert(1);
        }
        else
        {
            it--;
            team.insert(*it + 1);
            team.erase(it);
        }
    }

    cout << team.size();
}