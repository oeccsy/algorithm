#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> terms_table;

vector<string> split(string target, string sep)
{
    vector<string> result;

    int st = 0;
    int en = 0;

    while (true)
    {
        en = target.find(sep, st);
        if (en == string::npos) break;

        string token = target.substr(st, en - st);
        result.push_back(token);

        st = en + sep.length();
    }

    result.push_back(target.substr(st, en - st));

    return result;
}

void print(vector<string>& target)
{
    for (auto str : target)
    {
        cout << str << '\n';
    }
}

int get_day_count(vector<string>& date)
{
    // 2000년 1월 1일로부터 몇 번째 날인가?
    int year = stoi(date[0]);
    int month = stoi(date[1]);
    int day = stoi(date[2]);

    return (year - 2000) * 12 * 28 + (month - 1) * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;

    vector<string> today_tokens = split(today, ".");
    int today_day_count = get_day_count(today_tokens);

    for (auto term : terms)
    {
        vector<string> term_tokens = split(term, " ");

        string key = term_tokens[0];
        int value = stoi(term_tokens[1]) * 28;
        terms_table[key] = value;
    }

    for (int i = 1; i <= privacies.size(); ++i)
    {
        string privacy = privacies[i - 1];
        vector<string> split_with_space = split(privacy, " ");
        vector<string> date_tokens = split(split_with_space[0], ".");
        string term_key = split_with_space[1];

        int date_day_count = get_day_count(date_tokens);
        int term_day_count = terms_table[term_key];

        if (date_day_count + term_day_count <= today_day_count) answer.push_back(i);

    }

    return answer;
}