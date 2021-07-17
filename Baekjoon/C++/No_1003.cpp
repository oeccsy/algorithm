#include <iostream>

using namespace std;


int t;

int count_0[43] = { 1, 0, 0, };
int count_1[43] = { 0, 1, 0, };

void fibonacci() {

    for (int i = 0; i < 40; i++)
    {
        count_0[i + 2] = count_0[i + 1] + count_0[i];
        count_1[i + 2] = count_1[i + 1] + count_1[i];
    }
}

int main()
{
    fibonacci();
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << count_0[n] << " " << count_1[n] << "\n";
    }
}