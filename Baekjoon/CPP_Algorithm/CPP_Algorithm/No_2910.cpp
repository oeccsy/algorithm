#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Number
{
    long long number;
    int count;
    int index;
};

vector<Number> nums;

bool Compare(Number& a, Number& b)
{
    if(a.count != b.count)
    {
        return a.count > b.count;
    }

    return a.index < b.index;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    
    for (int i = 0; i < n; i++)
    {
        long long input;
        cin >> input;

        bool is_exist = false;

        for(Number& num : nums)
        {
            if(num.number == input)
            {
                num.count++;
                is_exist = true;
                break;
            }
        }

        if(is_exist == false)
        {
            Number new_number = {input, 1, i};
            nums.push_back(new_number);
        }
    }

    sort(nums.begin(), nums.end(), Compare);

    for(auto num : nums)
    {
        for(int i=0; i<num.count; i++)
        {
            cout << num.number << " ";
        }
    }
}
