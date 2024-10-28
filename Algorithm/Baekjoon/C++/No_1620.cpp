#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 번호 -> 이름, 이름 -> 번호
    // 도감 포켓몬 수 n, 문제 수 m
    // 1 <= n, m <= 100000
    // 영어
    // 첫글자만 대문자, 일부 포켓몬은 마지막 문제만 대문자

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> s_dict;
    unordered_map<int, string> i_dict;
    

    for(int i=1; i<=n; i++)
    {
        string name;
        cin >> name;

        s_dict[name] = i;
        i_dict[i] = name;
    }

    for(int i=0; i<m; i++)
    {
        string question;
        cin >> question;

        if('A' <= question[0] && question[0] <= 'z')
        {
            cout << s_dict[question] << '\n';
        }
        else
        {
            cout << i_dict[stoi(question)] << '\n';
        }
    }
}