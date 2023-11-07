#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct ClassTime
{
    int s;
    int t;
};

bool cmp(ClassTime* a, ClassTime* b)
{
    if(a->s != b->s)
    {
        return a->s < b->s;
    }
    else
    {
        return a->t < b->t;
    }
}

vector<ClassTime*> class_times;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int s_input, t_input;
        cin >> s_input >> t_input;
        
        ClassTime* new_class = new ClassTime{s_input, t_input};
        class_times.push_back(new_class);
    }
    
    sort(class_times.begin(), class_times.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(class_times[0]->t);
    
    for(int i=1; i<class_times.size(); i++)
    {
        ClassTime* cur_class = class_times[i];
        pq.push(cur_class->t);
        
        if(pq.top() <= cur_class->s)
        {
            pq.pop();
        }
    }

    cout << pq.size();
}