#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<bool, 31> assignment;

    for(int i=1; i<=30; i++)
    {
        assignment[i] = false;
    }

    for(int i=0; i<28; i++)
    {
        int input = 0;
        cin >> input;

        assignment[input] = true;
    }

    for(int i=1; i<=30; i++)
    {
        if(assignment[i] == false)
            cout << i << '\n';
    }
}