#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int,3> dice = {0, };

    for(int i=0; i<3; i++)
    {
        cin >> dice[i];
    }

    if(dice[0] == dice[1] && dice[1] == dice[2])
    {
        cout << 10000 + dice[0] * 1000;
    }
    else if(dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[0])
    {
        int sameNum = (dice[0] == dice[1]) ? dice[0] : dice[2];
        cout << 1000 + sameNum * 100;
    }
    else
    {
        int maxNum = max({dice[0], dice[1], dice[2]});
        cout << maxNum * 100;
    }
    
    
}