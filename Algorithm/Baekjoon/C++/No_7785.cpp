#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 직원들은 9시부터 6시까지 회사에 있지 않아도 된다.
    // 원할 떄 출근, 아무 때 퇴근
    // 로그가 주어졌을 때, 회사에 있는 모든 사람을 구하라

    // 출입 수 n
    // enter 출근 leave 퇴근

    set<string, greater<string>> people;

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        string name, info;
        cin >> name >> info;

        if(info == "enter")
        {
            people.insert(name);
        }
        else
        {
            people.erase(name);
        }
    }

    for(auto& person : people)
    {
        cout << person << '\n';
    }
}