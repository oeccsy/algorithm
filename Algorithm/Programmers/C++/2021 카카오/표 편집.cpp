#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stack>

using namespace std;

// 명령어 기반의 행 선택, 삭제, 복구
// 파란 칸 : 현재 선택된 행
// 한번에 한 행만 선택

// 명령어
// U X : x칸 위 (x칸 이전 iter) 선택
// D X : x칸 밑 (x칸 이후 iter) 선택 
// C : 선택된 행 삭제, 선택은 다음 행, "삭제된 행이 마지막인 경우 바로 윗 행 선택"
// Z : 원래대로 복구 "선택된 행은 바뀌지 않음"

// 표 이전/이후 상태 비교하여 존재 O 삭제 X로 표시 하여 문자열 형태로 Return
// n 처음 표 행 개수, k : 처음 행 개수

// 연결리스트 직접 구현

struct Node
{
    int index;
    Node* prev;
    Node* next;
};

Node* begin;
Node* end;

string solution(int n, int k, vector<string> cmd)
{
    Node* begin = new Node();
    Node* end = new Node();
    
    begin->next = end;
    end->prev = begin;

    string answer;
    answer.reserve(n);
    
    for(int i=0; i<n; i++)
    {
        Node* new_node = new Node();
        new_node->index = i;
        
        new_node->prev = end->prev;
        new_node->next = end;
        
        end->prev->next = new_node;
        end->prev = new_node;
        
        answer.push_back('X');
    }
    
    Node* selected = begin->next;
    for(int i=0; i<k; i++)
    {
        selected = selected->next;
    }
    
    stack<Node*> removed_nodes;
    
    for(auto cur_cmd : cmd)
    {
        switch(cur_cmd[0])
        {
            case 'U':
                for(int i=0; i<stoi(cur_cmd.substr(2, cur_cmd.size() - 2)); i++)
                {
                    selected = selected->prev;
                }
                break;
            case 'D':
                for(int i=0; i<stoi(cur_cmd.substr(2, cur_cmd.size() - 2)); i++)
                {
                    selected = selected->next;
                }
                break;
            case 'C':
                selected->prev->next = selected->next;
                selected->next->prev = selected->prev;
                
                removed_nodes.push(selected);
                selected = selected->next;
                if(selected == end) selected = selected->prev;
                break;
            case 'Z':
                Node* removed_node = removed_nodes.top();
                removed_nodes.pop();
                
                removed_node->prev->next = removed_node;
                removed_node->next->prev = removed_node;
                break;
        }
    }
   
    Node* cur_node = begin->next;
    
    while(cur_node != end)
    {
        answer[cur_node->index] = 'O';
        cur_node = cur_node->next;
    }
    
    return answer;
}