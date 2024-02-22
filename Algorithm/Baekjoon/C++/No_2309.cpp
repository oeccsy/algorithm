#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 9> height = {0, };
    int total = 0;
    int liar_a, liar_b;
    
    for(int i=0; i<9; i++)
    {
        cin >> height[i];
        total += height[i];
    }

    sort(height.begin(), height.end());

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if (i==j) continue;

            if(total - height[i] - height[j] == 100)
            {
                liar_a = i;
                liar_b = j;

                i = 10;
                break;
            }
        }
    }

    for(int k=0; k<9; k++)
    {
        if(k == liar_a || k == liar_b) continue;
        cout << height[k] << '\n';
    }

    
}