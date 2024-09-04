#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node
{
    string name;
    unordered_map<string, int> prev_gifts;
    int gift_value = 0;
    int next_gifts_count = 0;
};

unordered_map<string, Node*> nodes;

vector<string> split(string input, string split_target)
{
    vector<string> result;
    int pos = 0;
    while((pos = input.find(split_target)) != string::npos)
    {
        string token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + split_target.size());
    }
    
    result.push_back(input);
    
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(auto iter=friends.begin(); iter!=friends.end(); iter++)
    {
        Node* new_node = new Node();
        new_node->name = *iter;
        nodes.insert({*iter, new_node});
    }
    
    for(auto iter=gifts.begin(); iter!=gifts.end(); iter++)
    {
        vector<string> tokens = split(*iter, " ");
        string src = tokens[0];
        string dest = tokens[1];
        
        nodes[src]->gift_value++;
        nodes[dest]->gift_value--;
        
        unordered_map<string, int>& prev_gifts = nodes[src]->prev_gifts;
        
        if(prev_gifts.find(dest) == prev_gifts.end())
        {
            prev_gifts[dest] = 1;
        }
        else
        {
            prev_gifts[dest] += 1;
        }
    }
    
    for(auto iter=friends.begin(); iter!=friends.end(); iter++)
    {
        Node* cur_node = nodes[*iter];
        
        for(auto f_iter=friends.begin(); f_iter!=friends.end(); f_iter++)
        {
            if(iter == f_iter) continue;
            
            Node* f_node = nodes[*f_iter];
            
            int c_to_f = 0;
            int f_to_c = 0;
            
            if(cur_node->prev_gifts.find(*f_iter) != cur_node->prev_gifts.end()) c_to_f = cur_node->prev_gifts[*f_iter];
            if(f_node->prev_gifts.find(*iter) != f_node->prev_gifts.end()) f_to_c = f_node->prev_gifts[*iter];
            
            if(c_to_f > f_to_c)
            {
                cur_node->next_gifts_count++;
            }
            else if(c_to_f == f_to_c && cur_node->gift_value > f_node->gift_value)
            {
                cur_node->next_gifts_count++;
            }
            
            answer = max(answer, cur_node->next_gifts_count);
        }
    }
    
    return answer;
}