#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int k=1; k<=t; k++)
    {
        int n, d, b, e;
        cin >> n >> d >> b >> e;

        int calc_target = n % d;
        vector<int> decimal;

        for(int i=0; i<=e; i++)
        {
            calc_target *= 7;
            int decimal_i = calc_target / d;
            calc_target %= d;

            decimal.push_back(decimal_i); 
        }

        cout << "Problem set " << k << ": " << n << " / " << d << ", base 7 digits " << b << " through " << e << ": ";

        for(int i=b; i<=e; i++)
        {
            cout << decimal[i];
        }

        cout << '\n';
    }
}