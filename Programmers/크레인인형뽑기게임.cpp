#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> S;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    
    for(int moves_index =0; moves_index<moves.size(); moves_index++)
    {
        int crain = moves[moves_index]-1;
        
        for(int board_index = 0; board_index < board[crain].size(); board_index++)
        {
            if(board[board_index][crain] == 0)
                continue;

            if(!S.empty())
            {
                if(board[board_index][crain] == S.top())
                {
                    board[board_index][crain] = 0;
                S.pop();
                answer+=2;
                break;
                }
            }
            S.push(board[board_index][crain]);
            board[board_index][crain] = 0;
            break;
        }
    }
    
    return answer;
}