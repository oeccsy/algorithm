#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int first_num, second_num;
    cin >> first_num >> second_num;

    cout << first_num * (second_num % 10) << "\n";
    cout << first_num * (second_num / 10 % 10) << "\n";
    cout << first_num * (second_num / 100 % 10) << "\n";
    cout << first_num * second_num << "\n";
}