#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool is_a[11] = {false, };
vector<int> a_cur_comb;
vector<int> b_cur_comb;
vector<vector<int>> a_all_comb;
vector<vector<int>> b_all_comb;

int a_cur_sum = 0;
int b_cur_sum = 0;
vector<int> a_comb_sum;
vector<int> b_comb_sum;

void dfs(int cur_index, int min_value, int max_value, int n)
{
    if(cur_index == n / 2)
    {
        for(int i=1; i<=n; i++)
        {
            if(is_a[i])
            {
                a_cur_comb.push_back(i);
            }
            else
            {
                b_cur_comb.push_back(i);
            }
        }
        
        a_all_comb.push_back(a_cur_comb);
        b_all_comb.push_back(b_cur_comb);
        
        a_cur_comb.clear();
        b_cur_comb.clear();
        return;
    }
    
    for(int i=min_value; i<=max_value; i++)
    {
        is_a[i] = true;
        dfs(cur_index + 1, i + 1, max_value, n);
        is_a[i] = false;
    }
}

void calc_sum(int depth, int comb_index, vector<vector<int>>& dice)
{   
    if(depth == dice.size() / 2)
    {
        a_comb_sum.push_back(a_cur_sum);
        b_comb_sum.push_back(b_cur_sum);
        return;
    }
    
    int a_dice_num = a_all_comb[comb_index][depth];
    int b_dice_num = b_all_comb[comb_index][depth];
    
    for(int i=0; i<6; i++)
    {
        a_cur_sum += dice[a_dice_num-1][i];
        b_cur_sum += dice[b_dice_num-1][i];
        calc_sum(depth + 1, comb_index, dice);
        a_cur_sum -= dice[a_dice_num-1][i];
        b_cur_sum -= dice[b_dice_num-1][i];
    }
}

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    int max_win_count = 0;
    
    dfs(0, 1, dice.size(), dice.size());
    
    for(int i=0; i<a_all_comb.size(); i++)
    {
        a_comb_sum.clear();
        b_comb_sum.clear();
        
        calc_sum(0, i, dice);
        
        sort(a_comb_sum.begin(), a_comb_sum.end());
        sort(b_comb_sum.begin(), b_comb_sum.end());
        
        int win_count = 0;
        for(int j=0; j<a_comb_sum.size(); j++)
        {
            win_count += (lower_bound(b_comb_sum.begin(), b_comb_sum.end(), a_comb_sum[j]) - b_comb_sum.begin());
            
            if(win_count > max_win_count)
            {
                answer = a_all_comb[i];
                max_win_count = win_count;
            }
        }
    }
    
    return answer;
}