#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    int b;
    int c;

    int end_h = 0;
    int end_m = 0;
    
    cin >> a >> b;
    cin >> c;

    end_h = a;
    end_m = b + c;

    while(end_m >= 60)
    {
        end_h += 1;
        end_m -= 60;
    }

    while(end_h >= 24)
    {
        end_h -= 24;
    }

    cout << end_h << " " << end_m;
}