#include <iostream>
#include <stack>

using namespace std;

struct People
{
    int height;
    int count;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<People> people_stack;
    int n;
  
    long long result = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;

        People new_person = {input, 1};
        
        while(!people_stack.empty())
        {
            if(people_stack.top().height < new_person.height)
            {
                //cout << "Case 1 : " << people_stack.top().height << " " << input << endl;
                result += people_stack.top().count;
                people_stack.pop();
            }
            else if(people_stack.top().height == new_person.height)
            {
                //cout << "Case 2 : " << people_stack.top().height << " " << input << " " << people_stack.top().count <<endl;
                result += people_stack.top().count;
                new_person.count += people_stack.top().count;
                people_stack.pop();
            }
            else
            {
                //cout << "Case 3 : " << people_stack.top().height << " " << input <<endl;
                result++;
                break;
            }
        }
        
        people_stack.push(new_person);
    }

    cout << result;
}
