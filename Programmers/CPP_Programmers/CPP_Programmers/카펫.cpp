#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w = 1;
    int h = 1;
    
    //2 * w * h = 2 * (brown + yellow);
    //2 * (w + h) = brown + 4;
    
    while(true)
    {
        if(w * (brown + 4 - 2 * w) == 2 * (brown + yellow)) break;
        
        w++;
    }
    
    h = (brown + 4 - 2 * w) / 2;
    
    if(w < h)
    {
        int temp = w;
        w = h;
        h = temp;
    }
    
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}