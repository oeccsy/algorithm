#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> rope_values;
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int rope_value_input;
        cin >> rope_value_input;

        rope_values.push_back(rope_value_input);
    }

    sort(rope_values.begin(), rope_values.end(), greater<int>());

    int cur_rope_count = 0;
    int max_weight = 0;

    for(const auto& rope_value : rope_values)
    {
        cur_rope_count++;
        int cur_weight = cur_rope_count * rope_value;
        
        if(max_weight < cur_weight) max_weight = cur_weight;
    }

    cout << max_weight;
}