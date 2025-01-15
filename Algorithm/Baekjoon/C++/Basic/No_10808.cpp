#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 26> alphabet = {0, };
    string input;

    cin >> input;

    for(int i=0; i<input.length(); i++)
    {
        alphabet[input[i] - 'a']++;
    }

    for(int i=0; i<alphabet.size(); i++)
    {
        cout << alphabet[i] << " ";   
    }
}