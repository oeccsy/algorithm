#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower
{
    int begin_date;
    int end_date;
};

vector<Flower*> flowers;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int b_m, b_d, e_m, e_d;
        cin >> b_m >> b_d >> e_m >> e_d;
        
        Flower* new_flower = new Flower{b_m * 100 + b_d, e_m * 100 + e_d};
        flowers.push_back(new_flower);
    }
    
    int result = 0;
    int target_date = 301;

    while(target_date < 1201)
    {
        int new_target_date = target_date;
        
        for(int i=0; i<n; i++)
        {
            if(flowers[i]->begin_date <= target_date && flowers[i]->end_date > new_target_date)
            {
                new_target_date = flowers[i]->end_date;
            }
        }

        if(new_target_date == target_date)
        {
            cout << 0;
            return 0;
        }

        target_date = new_target_date;
        result++;
    }

    cout << result;
}