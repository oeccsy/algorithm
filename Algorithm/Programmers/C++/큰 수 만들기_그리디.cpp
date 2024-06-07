#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    while(k--)
    {
        int target_index = 0;
        
        for(int i=0; i<number.size(); i++)
        {
            if(i+1 == number.size())
            {
                target_index = i;
                break;
            }
            
            if(number[i] < number[i+1]) 
            {
                target_index = i;
                break;
            }
        }
        
        number.erase(target_index, 1);
    }
    
    answer = number;
    return answer;
}