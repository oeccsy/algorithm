#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calc = 0;
int count = 0;

void dfs(int depth, int max_depth, bool add, vector<int>& numbers, int target)
{
    if(depth == max_depth)
    {
        if(calc == target) count++;
        return;
    }
    
    if(add)
    {
        calc += numbers[depth];
        dfs(depth + 1, max_depth, true, numbers, target);
        dfs(depth + 1, max_depth, false, numbers, target);
        calc -= numbers[depth];
    }
    else
    {
        calc -= numbers[depth];
        dfs(depth + 1, max_depth, true, numbers, target);
        dfs(depth + 1, max_depth, false, numbers, target);
        calc += numbers[depth];
    }
}

int solution(vector<int> numbers, int target)
{
    dfs(0, numbers.size(), true, numbers, target);
    dfs(0, numbers.size(), false, numbers, target);
    return count / 2;
}