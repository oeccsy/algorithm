#include <iostream>

using namespace std;

int move_count = 0;

void MoveTower(int start, int end, int height)
{
    if(height == 0)
    {
        return;
    }
    if(height == 1)
    {
        cout << start << " " << end << '\n';
        return;
    }

    int temp_area = 6-start-end;
    MoveTower(start, temp_area, height-1);
    MoveTower(start, end, 1);
    MoveTower(temp_area, end, height-1);
}

int main()
{
    int n;
    cin >> n;

    cout << (1<<n) -1 << '\n'; // 횟수 구하는 방법은 바킹독 강의를 참고
    MoveTower(1, 3, n);
}