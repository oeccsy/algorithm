#include <iostream>
#include <string>

using namespace std;

int main()
{
    int p;
    cin >> p;

    for(int i=0; i<p; i++)
    {
        int r;
        string s;

        cin >> r >> s;

        for(auto c : s)
        {
            for(int j=0; j<r; j++)
            {
                cout << c;
            }
        }
        cout << '\n';
    }
}