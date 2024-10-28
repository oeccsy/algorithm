#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 메모장에 사이트 주소와 비밀번호 저장
    // 주소 수 n, 문제 수 m
    
    unordered_map<string, string> passwords;
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        string site, password;
        cin >> site >> password;
        passwords[site] = password;
    }

    for(int i=0; i<m; i++)
    {
        string site;
        cin >> site;
        cout << passwords[site] << '\n';
    }
}