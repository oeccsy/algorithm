#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> pattern;

int select_long_term(vector<int>& pattern, vector<int>::iterator iter, unordered_set<int> set)
{
    while(iter != pattern.end() && set.size() > 1)
    {    
        if(set.find(*iter) != set.end()) set.erase(*iter);
        iter++;
    }

    return *(set.begin());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 한 개의 멀티탭 이용
    // 여러 디바이스가 점유
    // 플러그를 빼는 횟수를 최소화 하는 방법
    
    // 멀티탭 구멍 개수 N
    // 전기 용품의 총 사용 횟수 K
    // 전기 용품 값 자연수

    int n, k;
    cin >> n >> k;

    for(int i=0; i<k; i++)
    {
        int input;
        cin >> input;
        pattern.push_back(input);
    }

    unordered_set<int> multi_tap;
    int remove_count = 0;

    for(auto iter = pattern.begin(); iter != pattern.end(); iter++)
    {
        int cur_device = *iter; 
        if(multi_tap.find(cur_device) != multi_tap.end()) continue;
        
        if(multi_tap.size() >= n)
        {
            int erase_target = select_long_term(pattern, iter, multi_tap);
            multi_tap.erase(erase_target);
            remove_count++;
        }

        multi_tap.insert(cur_device);
    }

    cout << remove_count;
}