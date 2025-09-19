#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    int row;
    int col;

    string value;

    Node* parent;
};

Node* nodes[51][51];

vector<string> split(string target, string sep)
{
    vector<string> result;

    int st = 0;
    int en = 0;

    while (true)
    {
        en = target.find(sep, st);
        if (en == string::npos)
        {
            string token = target.substr(st);
            result.push_back(token);
            break;
        };

        string token = target.substr(st, en - st);
        result.push_back(token);

        st = en + sep.length();
    }

    return result;
}

Node* find(Node* node)
{
    if (node->parent != node)
    {
        node->parent = find(node->parent);
    }

    return node->parent;
}

void update(int r, int c, string value)
{
    find(nodes[r][c])->value = value;
}

void update(string value1, string value2)
{
    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            Node* target = find(nodes[i][j]);
            if (target->value == value1) target->value = value2;
        }
    }
}

void merge(int r1, int c1, int r2, int c2)
{
    Node* root_1 = find(nodes[r1][c1]);
    Node* root_2 = find(nodes[r2][c2]);

    if (root_1 != root_2)
    {
        if (root_1->value == "")
        {
            root_1->value = root_2->value;
        }

        root_2->parent = root_1;
    }
}

void unmerge(int r, int c)
{
    Node* target = find(nodes[r][c]);
    string value = target->value;

    Node* roots[51][51];

    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            roots[i][j] = find(nodes[i][j]);
        }
    }

    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            if (roots[i][j] == target)
            {
                nodes[i][j]->parent = nodes[i][j];
                nodes[i][j]->value = "";
            }
        }
    }

    nodes[r][c]->value = value;
}

void print(int r, int c, vector<string>& answer)
{
    Node* target = find(nodes[r][c]);

    string value = (target->value.empty()) ? "EMPTY" : target->value;
    answer.push_back(value);
}

vector<string> solution(vector<string> commands)
{
    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            Node* new_node = new Node();
            new_node->row = i;
            new_node->col = j;
            new_node->value = "";
            new_node->parent = new_node;

            nodes[i][j] = new_node;
        }
    }

    vector<string> answer;

    for (auto& command : commands)
    {
        vector<string> command_tokens = split(command, " ");
        string type = command_tokens[0];

        if (type == "UPDATE")
        {
            if (command_tokens.size() == 4)
            {
                int r = stoi(command_tokens[1]);
                int c = stoi(command_tokens[2]);
                string value = command_tokens[3];

                update(r, c, value);
            }
            else if (command_tokens.size() == 3)
            {
                string value1 = command_tokens[1];
                string value2 = command_tokens[2];

                update(value1, value2);
            }
        }
        else if (type == "MERGE")
        {
            int r1 = stoi(command_tokens[1]);
            int c1 = stoi(command_tokens[2]);
            int r2 = stoi(command_tokens[3]);
            int c2 = stoi(command_tokens[4]);

            merge(r1, c1, r2, c2);
        }
        else if (type == "UNMERGE")
        {
            int r = stoi(command_tokens[1]);
            int c = stoi(command_tokens[2]);

            unmerge(r, c);
        }
        else if (type == "PRINT")
        {
            int r = stoi(command_tokens[1]);
            int c = stoi(command_tokens[2]);

            print(r, c, answer);
        }
    }

    return answer;
}