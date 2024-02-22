#include <iostream>
#include <stack>
#include <xmmintrin.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> building;
    int n;
    long long result = 0;

    cin >> n;

    for(int i=0; i<n; i++)
    {
    	int height;
    	cin >> height;

    	while(true)
    	{
    		if(building.empty())
    		{
    			building.push(height);
    			break;
    		}
    		else if(building.top() > height)
    		{
    			result += building.size();
    			building.push(height);
    			break;
    		}
    		else
    		{
    			building.pop();
    		}	
    	}
    }

	cout << result;
}
