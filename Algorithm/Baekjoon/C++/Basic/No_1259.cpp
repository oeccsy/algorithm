#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    
    while(true)
    {
        cin >> input;

        if(input == "0") return 0;

        int left = 0;
        int right = input.size() - 1;

        while(left <= right)
        {
            if(input[left] == input[right])
            {
                left++;
                right--;
            }
            else
            {
                break;
            }
        }

        if(left < right)
        {
            cout << "no" << '\n';
        }
        else
        {
            cout << "yes" << '\n';
        }
    }
}