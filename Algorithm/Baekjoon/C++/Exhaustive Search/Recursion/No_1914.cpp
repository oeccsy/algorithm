#include <iostream>

using namespace std;

void move_tower(int h, int st, int en)
{
    if(h==1)
    {
        cout << st << " " << en << '\n';
        return;
    }

    int temp = 6 - st - en;
    move_tower(h-1, st, temp);
    move_tower(1, st, en);
    move_tower(h-1, temp, en);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    cout << ((long long)1 << n) - 1 << '\n';

    if(n <= 20) move_tower(n, 1, 3);
}

// 2의 20제곱은 long long으로도 해결 할 수 없다!