#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if(num ==2)
        return true;
    for(int i = 2; i <= num/2; i++) {
        if(num%i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    
    int check[3000] = {0, };
    int answer = 0;
    int sum = 0;
    
    for(int i = 0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            for(int k=j+1; k<nums.size(); k++) {
                if(isPrime(nums[i]+nums[j]+nums[k]))
                    answer++;
                }
            }
        }
    return answer;
}