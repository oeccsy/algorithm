#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;

    while(true)
    {
        cin >> a >> b;

        if(cin.eof())
            break;
        
        cout << a + b << '\n';
    }
}