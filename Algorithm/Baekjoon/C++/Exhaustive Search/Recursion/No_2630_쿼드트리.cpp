#include <iostream>

using namespace std;

int paper[128][128];
int w_count = 0;
int b_count = 0;

void count_papers(int n, int r, int c)
{
    if(n==1)
    {
        if(paper[r][c] == 0) w_count++;
        if(paper[r][c] == 1) b_count++;
        return;
    }

    for(int i=r; i<r+n; i++)
    {
        for(int j=c; j<c+n; j++)
        {
            if(paper[i][j] != paper[r][c])
            {
                count_papers(n/2, r, c);
                count_papers(n/2, r+n/2, c);
                count_papers(n/2, r, c+n/2);
                count_papers(n/2, r+n/2, c+n/2);
                return;
            }
        }
    }

    if(paper[r][c] == 0) w_count++;
    if(paper[r][c] == 1) b_count++;
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
            cin >> paper[i][j];
        }
    }

    count_papers(n, 0, 0);

    cout << w_count << '\n';
    cout << b_count;
}