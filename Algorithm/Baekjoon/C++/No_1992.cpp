#include <iostream>

using namespace std;

char image[64][64];
string code;

void create_code(int n, int r, int c)
{
    for(int i=r; i<r+n; i++)
    {
        for(int j=c; j<c+n; j++)
        {
            if(image[i][j] != image[r][c])
            {
                code.push_back('(');
                create_code(n/2, r, c);
                create_code(n/2, r, c+n/2);
                create_code(n/2, r+n/2, c);
                create_code(n/2, r+n/2, c+n/2);
                code.push_back(')');
                return;
            }
        }
    }

    code.push_back(image[r][c]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> image[i][j];
        }
    }

    create_code(n, 0, 0);
    cout << code;
}