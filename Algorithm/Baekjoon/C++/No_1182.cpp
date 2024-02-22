#include <iostream>

using namespace std;

int n, s;
int integer[20];
int result = 0;

void Count(int index, int sum)
{
    if(index == n)
    {
        if(sum == s) result++;
        return;
    }

    Count(index+1, sum);                // 부분수열에 포함하지 않거나
    Count(index+1, sum+integer[index]); // 부분수열에 포함하거나
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> s;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        integer[i] = input;
    }

    Count(0, 0);

    if(s==0) result -= 1;   // 크기가 0인 경우

    cout << result;
}