#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

// n x m 격자 미로
// x,y 시작, r, c 탈출

// 3가지 조건
// 격자 밖 못나감
// 총 거리가 k
// 미로 탈출 경로 문자열로 나타냈을 때 사전순으로 빠른 경로로 탈출

// 조건대로 탈출 할 수 없는 경우 impossible 리턴

struct Node
{
    int r;
    int c;
};

int dr[4] = { 1, 0, 0, -1 };
int dc[4] = { 0, -1, 1, 0 };

int req_move_count[4];

int get_u_dist(Node start, Node goal) { return (start.r > goal.r) ? start.r - goal.r : 0; }
int get_d_dist(Node start, Node goal) { return (start.r < goal.r) ? goal.r - start.r : 0; }
int get_l_dist(Node start, Node goal) { return (start.c > goal.c) ? start.c - goal.c : 0; }
int get_r_dist(Node start, Node goal) { return (start.c < goal.c) ? goal.c - start.c : 0; }

int N, M;

void dfs(Node cur, Node& goal, string& answer, int& k, int& over)
{
    if (answer.size() == k) return;

    if (req_move_count[0] > 0)
    {
        answer.push_back('d');
        --req_move_count[0];
        dfs({ cur.r + 1, cur.c }, goal, answer, k, over);
    }
    else if (cur.r < N && over > 0)
    {
        answer.push_back('d');
        ++req_move_count[3];
        over -= 2;
        dfs({ cur.r + 1, cur.c }, goal, answer, k, over);
    }
    else if (req_move_count[1] > 0)
    {
        answer.push_back('l');
        --req_move_count[1];
        dfs({ cur.r, cur.c - 1 }, goal, answer, k, over);
    }
    else if (cur.c > 1 && over > 0)
    {
        answer.push_back('l');
        ++req_move_count[2];
        over -= 2;
        dfs({ cur.r, cur.c - 1 }, goal, answer, k, over);
    }
    else if (req_move_count[2] > 0)
    {
        answer.push_back('r');
        --req_move_count[2];
        dfs({ cur.r, cur.c + 1 }, goal, answer, k, over);
    }
    else if (cur.c < M && over > 0)
    {
        answer.push_back('r');
        ++req_move_count[1];
        over -= 2;
        dfs({ cur.r, cur.c + 1 }, goal, answer, k, over);
    }

    else if (req_move_count[3] > 0)
    {
        answer.push_back('u');
        --req_move_count[3];
        dfs({ cur.r - 1, cur.c }, goal, answer, k, over);
    }
    else if (cur.c > 0 && over > 0)
    {
        answer.push_back('u');
        ++req_move_count[0];
        over -= 2;
        dfs({ cur.r - 1, cur.c }, goal, answer, k, over);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    N = n;
    M = m;

    string answer = "";

    Node start = { x, y };
    Node goal = { r, c };

    req_move_count[0] = get_d_dist(start, goal);
    req_move_count[1] = get_l_dist(start, goal);
    req_move_count[2] = get_r_dist(start, goal);
    req_move_count[3] = get_u_dist(start, goal);

    int dist = 0;
    for (int i = 0; i < 4; ++i) dist += req_move_count[i];

    int over = k - dist;

    cout << dist << k << endl;

    if (k < dist)
    {
        answer = "impossible";
    }
    else if (over % 2 == 1)
    {
        answer = "impossible";
    }
    else
    {
        dfs(start, goal, answer, k, over);
    }

    return answer;
}