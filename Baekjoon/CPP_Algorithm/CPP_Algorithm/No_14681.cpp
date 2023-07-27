#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    int y;
    int quadrant;
    cin >> x;
    cin >> y;

    if(x > 0 && y > 0)
    {
        quadrant = 1;
    }
    else if (x < 0 && y > 0)
    {
        quadrant = 2;
    }
    else if (x < 0 && y < 0)
    {
        quadrant = 3;
    }
    else if (x > 0 && y < 0)
    {
        quadrant = 4;
    }

    cout << quadrant;
}