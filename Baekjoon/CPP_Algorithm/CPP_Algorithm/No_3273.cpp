#include <iostream>

using namespace std;

int n;
int a[1000001] = {0, };
int x;
int ij_count = 0;
int duplication = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        int input;
        cin >> input;
        a[input]++;
    }

    cin >> x;

    for(int i=1; i < (x+1)/2 ; i++)
    {
        if(x-i <= 0 || x-i > 1000000) continue;
        
        if(a[i] == 1 && a[x-i] == 1) //i == 1000000 에서 카운트 오류 => i == (x+1)/2 인 경우를 반복문에서 포함하면 안됨
        {
            ij_count++;
        }
    }

    if(x >= 1000000) ij_count /= 2;
    cout << ij_count;
}