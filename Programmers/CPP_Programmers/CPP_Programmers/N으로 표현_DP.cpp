#include <set>

using namespace std;

set<int> d[9];

int solution(int N, int number)
{
    if(N == number) return 1;
    
    int repeated_num = 0;
    for(int i=1; i<=8; i++)
    {
        repeated_num = 10 * repeated_num + N;
        d[i].insert(repeated_num);
    }
    
    for(int target=2; target<=8; target++)
    {
        for(int index_a=1; index_a<target; index_a++)
        {
            int index_b = target - index_a;
            
            set<int> group_a = d[index_a];
            set<int> group_b = d[index_b];
                
            for(auto num_a : group_a)
            {
                for(auto num_b : group_b)
                {
                    d[target].insert(num_a + num_b);
                    d[target].insert(num_a - num_b);
                    d[target].insert(num_a * num_b);
                    
                    if(num_b == 0) continue;
                    d[target].insert(num_a / num_b);
                }
            }
        }
        
        if(d[target].find(number) != d[target].end()) return target;
    }
    
    return -1;
}