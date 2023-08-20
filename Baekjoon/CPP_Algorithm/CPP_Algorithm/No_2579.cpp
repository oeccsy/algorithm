#include <iostream>

using namespace std;

int stairs[300];
int d[300][2]; // 현재 이전에 연속으로 현재와 연결되는 i(<2)개의 계단을 밟은 경우

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int stairs_count;
    cin >> stairs_count;

    for(int i=0; i<stairs_count; i++)
    {
        int input;
        cin >> input;
        stairs[i] = input;
    }

    d[0][0] = stairs[0];
    d[0][1] = 0;
    d[1][0] = stairs[1];
    d[1][1] = stairs[0] + stairs[1];

    for(int i=2; i<stairs_count; i++)
    {
        d[i][0] = max(d[i-2][0], d[i-2][1]) + stairs[i];
        d[i][1] = d[i-1][0] + stairs[i];
    }

    cout << max(d[stairs_count-1][0], d[stairs_count-1][1]);
}