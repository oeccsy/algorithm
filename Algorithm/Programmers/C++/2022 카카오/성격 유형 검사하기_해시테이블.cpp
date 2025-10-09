#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";

    unordered_map<char, int> scores;

    for (int i = 0; i < survey.size(); ++i)
    {
        char type = (choices[i] < 4) ? survey[i][0] : survey[i][1];
        int score = (choices[i] < 4) ? 4 - choices[i] : choices[i] - 4;

        scores[type] += score;
    }

    (scores['R'] >= scores['T']) ? answer.push_back('R') : answer.push_back('T');
    (scores['C'] >= scores['F']) ? answer.push_back('C') : answer.push_back('F');
    (scores['J'] >= scores['M']) ? answer.push_back('J') : answer.push_back('M');
    (scores['A'] >= scores['N']) ? answer.push_back('A') : answer.push_back('N');

    return answer;
}