#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> students;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 전체 학생 n명
    // 3명으로 구성된 팀
    // 코딩 실력 Ai -10000 ~ 10000
    // 합이 0이 되는 조합의 수

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;

        students.push_back(input);
    }

    sort(students.begin(), students.end());

    long long count = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int target = 0 - students[i] - students[j];
            
            auto lower_iter = lower_bound(students.begin(), students.end(), target);
            auto upper_iter = upper_bound(students.begin(), students.end(), target);
            
            int lower_index = lower_iter-students.begin();
            int upper_index = upper_iter-students.begin();

            if(upper_index <= j+1) continue;
            if(lower_index <= j+1) lower_index = j+1;
            
            count += upper_index - lower_index;
        }
    }

    cout << count;
}