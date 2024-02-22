#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if(n < 2) return false;
    
    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    set<int> num_set {};
    
    sort(numbers.begin(), numbers.end());
    
    do
    {
        string temp;
        for(int i=0; i<numbers.size(); i++)
        {
            temp += numbers[i];
            
            if(is_prime(stoi(temp))) num_set.insert(stoi(temp));
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    
    return num_set.size();
}