#include <iostream>

using namespace std;

int t;

int x1, y1, r1;
int x2, y2, r2;

int Distance1()
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int Distance2()
{
    return (r1+r2)*(r1+r2);
}

int Distance3()
{
    if(r1 > r2)
        return (r1-r2) * (r1-r2);
    else
        return (r2-r1) * (r2-r1); 
}

int main()
{
    cin >> t;

    for(int i = 0; i<t; i++)
    {
        

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if(x1 == x2 && y1 == y2 && r1 == r2)
            cout << -1 << "\n";
        else if(Distance1() > Distance2() || Distance1() < Distance3())
            cout << 0 << "\n";
        else if(Distance1() == Distance2() || Distance1() == Distance3())
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
        
        
    }
}