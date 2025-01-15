#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

struct Problem
{
    int num;
    int diff;

    bool operator<(const Problem& other) const
    {
        if(diff != other.diff) return diff < other.diff;
        else return num < other.num;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 문제번호, 난이도 정리
    // 명령어 3가지
    // recommend x -> 1은 가장 어려운 문제의 번호 출력, 어려운 문제 여러개면 번호 큰 것
    // -1은 가장 쉬운 문제 번호 출력, 쉬운 문제 여러개면 문제번호 작은 것
    // add P L : 난이도가 L인 문제 P를 추가
    // solved P : 난이도 P를 제거

    multiset<Problem> problems;
    unordered_map<int,int> diff_dict;

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int num_input, diff_input;
        cin >> num_input >> diff_input;

        Problem new_problem;
        new_problem.num = num_input;
        new_problem.diff = diff_input;
        problems.insert(new_problem);

        diff_dict[new_problem.num] = new_problem.diff;
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "recommend")
        {
            int arg;
            cin >> arg;

            auto it = (arg==1) ? --problems.end() : problems.begin();
            cout << it->num << '\n';
        }
        else if(cmd == "add")
        {
            int arg_num, arg_diff;
            cin >> arg_num >> arg_diff;

            problems.insert({arg_num, arg_diff});
            diff_dict[arg_num] = arg_diff;
        }
        else
        {
            int arg_num;
            cin >> arg_num;

            problems.erase({arg_num, diff_dict[arg_num]});
            diff_dict.erase(arg_num);
        }
    }
}