#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

char map[512][512];

void Fill(int r, int c, int n, string::iterator& it)
{
    if(*it == 'Q')
    {
        Fill(r, c, n/2, ++it);
        Fill(r, c+n/2, n/2, ++it);
        Fill(r+n/2, c, n/2, ++it);
        Fill(r+n/2, c+n/2, n/2, ++it);
    }
    else
    {   
        for(int i=r; i<r+n; i++)
        {
            for(int j=c; j<c+n; j++)
            {
                map[i][j] = *it;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string code;
    cin >> code;

    int r = 0;
    int c = 0;

    auto it = code.begin();
    Fill(0,0,n,it);

    cout << "#define quadtree_width " << n << '\n';
    cout << "#define quadtree_height " << n << '\n';
    cout << "static char quadtree_bits[] = {" << '\n';

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j+=8)
        {
            int byte = 0;

            for(int k=j; k<j+8; k++)
            {
                int bit = 1 << (k % 8);
                if(map[i][k] == 'B') byte += bit;
            }
            
            cout << "0x" << hex << setw(2) << setfill('0') << byte << ",";
        }

        cout << '\n';
    }

    cout << "};";
}
