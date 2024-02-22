#include <iostream>

using namespace std;

int ReturnOrder(int n, int r, int c)
{
    if(n == 1)
    {
        return  2 * r + c;
    }

    int side_length = 1;
    for(int i=0; i<n; i++) side_length *= 2;
    
    if(r >= side_length/2 && c >= side_length/2)
    {
        return ReturnOrder(n-1, r-side_length/2, c-side_length/2) + side_length/2 * side_length/2 * 3;
    }
    else if(r >= side_length/2)
    {
        return ReturnOrder(n-1, r-side_length/2, c) + side_length/2 * side_length/2 * 2;
    }
    else if(c >= side_length/2)
    {
        return ReturnOrder(n-1, r, c-side_length/2) + side_length/2 * side_length/2;
    }
    else
    {
        return ReturnOrder(n-1, r, c);
    }
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;

    cout << ReturnOrder(n, r, c);
}