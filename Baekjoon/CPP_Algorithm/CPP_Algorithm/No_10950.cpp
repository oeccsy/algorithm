﻿#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    int b;

    int t;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}