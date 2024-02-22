#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0; // w > h
    int max_h = 0;
    int answer = 0;
    
    for(auto business_card : sizes)
    {
        int cur_w, cur_h;
        
        if(business_card[0] > business_card[1])
        {
            cur_w = business_card[0];
            cur_h = business_card[1];
        }
        else
        {
            cur_w = business_card[1];
            cur_h = business_card[0];
        }
        
        if(max_w < cur_w) max_w = cur_w;
        if(max_h < cur_h) max_h = cur_h;
    }
    
    return max_w * max_h;
}