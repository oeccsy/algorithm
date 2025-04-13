#include <iostream>

using namespace std;

struct Matrix
{
    int r;
    int c;
};

Matrix mat[501];
int d[501][501]; // i~j까지 고려했을 때 최소 연산 횟수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        int r, c;
        cin >> r >> c;

        mat[i].r = r;
        mat[i].c = c;
    }

    for(int i=1; i<=n-1; i++)
    {
        d[i][i+1] = mat[i].r * mat[i].c * mat[i+1].c;
    }

    for(int gap=2; 1+gap<=n; gap++)
    {
        for(int left=1; left+gap<=n; left++)
        {
            int right = left + gap;

            for(int mid=left; mid<right; mid++)
            {
                int cur_count = d[left][mid] + d[mid+1][right] + mat[left].r * mat[mid].c * mat[right].c;
                if(d[left][right] == 0 || cur_count < d[left][right]) d[left][right] = cur_count;
            }
        }
    }

    cout << d[1][n];
}