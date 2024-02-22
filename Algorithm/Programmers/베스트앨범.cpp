#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> p;

bool genres_cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

bool plays_cmp(int a, int b)
{
    if(p[a] != p[b])
    {
        return p[a] > p[b];
    }
    else
    {
        return a < b;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    p = plays;
    
    unordered_map<string, int> popular_genres;
    unordered_map<string, vector<int>> popular_plays;
    
    for(int i=0; i<plays.size(); i++)
    {
        popular_genres[genres[i]]+=plays[i];
        popular_plays[genres[i]].push_back(i);
    }
    
    vector<pair<string, int>> popular_genres_v(popular_genres.begin(), popular_genres.end());
    sort(popular_genres_v.begin(), popular_genres_v.end(), genres_cmp);
    
    for(auto popular_genre : popular_genres_v)
    {
        sort(popular_plays[popular_genre.first].begin(), popular_plays[popular_genre.first].end(), plays_cmp);
        answer.push_back(popular_plays[popular_genre.first][0]);
        if(popular_plays[popular_genre.first].size() > 1)
        {
            answer.push_back(popular_plays[popular_genre.first][1]);
        }
    }
    return answer;
}