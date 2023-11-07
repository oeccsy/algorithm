#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line
{
    int x;
    int y;
};

vector<Line*> lines;

bool cmp(Line* a, Line* b)
{
    return a->x < b->x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int x_input, y_input;
        cin >> x_input >> y_input;
        
        Line* new_line = new Line{x_input, y_input};
        lines.push_back(new_line);
    }
    
    sort(lines.begin(), lines.end(), cmp);
    
    int result = 0;
    Line* prev_line = lines[0];
    
    for(int i=1; i<lines.size(); i++)
    {
        Line* cur_line = lines[i];
        
        if(cur_line->x <= prev_line->y)
        {
            prev_line->y = max(prev_line->y, cur_line->y);
        }
        else
        {
            result += prev_line->y - prev_line->x;
            
            prev_line->x = cur_line->x;
            prev_line->y = cur_line->y;
        }
    }

    result += prev_line->y - prev_line->x;
    
    cout << result;
}