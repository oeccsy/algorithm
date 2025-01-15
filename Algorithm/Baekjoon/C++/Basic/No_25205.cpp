#include <iostream>
#include <unordered_set>

using namespace std;

// 사용자 이름에 따라 '을' 또는 '를'출력
// 마지막 글자 받침 존재 여부

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;

    cin >> n;
    cin >> s;

    unordered_set<char> set = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v'};

    if(set.find(s[n-1]) == set.end())
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }
}