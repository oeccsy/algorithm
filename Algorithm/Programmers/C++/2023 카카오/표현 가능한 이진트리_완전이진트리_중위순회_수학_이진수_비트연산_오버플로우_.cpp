#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_binary(long long number)
{
    string binary;

    long long mask = 1;
    int len = 1;

    while (mask < number)
    {
        len += 1;
        len = len << 1;
        len -= 1;

        mask = 1LL << (len);
        mask -= 1;
    }

    for (int i = 1; i <= len; ++i)
    {
        if (number & (1LL << (len - i)))
        {
            binary.push_back('1');
        }
        else
        {
            binary.push_back('0');
        }
    }

    return binary;
}

bool visit(int st, int en, string& binary, bool& is_impossible)
{
    if (st > en) return true;
    if (is_impossible) return false;

    int mid = (st + en) / 2;
    char root = binary[mid];

    // 왼쪽 서브트리 방문
    bool left_subtree_only_0 = visit(st, mid - 1, binary, is_impossible);
    // 루트 노드 방문
    bool is_root_0 = (root == '0');
    // 오른쪽 서브트리 방문
    bool right_subtree_only_0 = visit(mid + 1, en, binary, is_impossible);

    if (is_root_0 && (!left_subtree_only_0 || !right_subtree_only_0)) is_impossible = true;

    return (is_root_0 && left_subtree_only_0 && right_subtree_only_0);
}

vector<int> solution(vector<long long> numbers)
{
    // 이진트리로 수를 표현할 수 있다면 1, 아니면 0 저장
    vector<int> answer;

    for (const auto& number : numbers)
    {
        string binary = to_binary(number);
        bool is_impossible = false;

        visit(0, binary.size() - 1, binary, is_impossible);

        int cur_answer = (is_impossible) ? 0 : 1;
        answer.push_back(cur_answer);
    }

    return answer;
}