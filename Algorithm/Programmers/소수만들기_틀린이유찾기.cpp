#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if(num ==2)
        return true;
    for(int i = 2; i <= num/2; i++) {
        if(num%i == 0 || num == 1 || num ==0 )
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

int wrong_solution(vector<int> nums) {
    
    int check[3000] = {0, };
    int answer = 0;
    int sum = 0;
    
    for(int i = 0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            for(int k=j+1; k<nums.size(); k++) {
                check[nums[i]+nums[j]+nums[k]] = 1;
            }
        }
    }
    
    for(int i=0; i<3000; i++) {
        if(check[i] ==1 && isPrime(i)==true)
            answer++;
    }
    
    return answer;
}

int main()
{
    vector<int> vec(50);

    for(int i=1; i<50; i++)
    {
        vec.push_back(i);
    }

    cout<< solution(vec) <<endl;
    //출력값 : 57498
    //소수가 만들어지는 "조합"의 수가 출력된다!

    cout <<wrong_solution(vec) <<endl;
    //출력값 : 36
    //만들어질 수 있는 "소수의 개수"가 출력된다!
}