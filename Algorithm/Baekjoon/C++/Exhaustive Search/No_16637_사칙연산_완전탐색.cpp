#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int max_result = numeric_limits<int>::min() + 1;

class Expression
{
public:
    Expression(string expression_str)
    {
        operands.reserve(10);
        operators.reserve(10);

        for(int i=0; i<expression_str.size(); i++)
        {
            if('0' <= expression_str[i] && expression_str[i] <= '9')
            {
                operands.push_back(expression_str[i] - '0');
            }
            else
            {
                operators.push_back(expression_str[i]);
            }
        }

        operator_count = operators.size();
    }

public:
    vector<int> operands;
    vector<char> operators;
    int operator_count;

public:
    void Calculate(int operator_index)
    {
        int operand_left = operands[operator_index];
        int operand_right = operands[operator_index + 1];
        char target_operator = operators[operator_index];
        
        int result;

        switch(target_operator)
        {
            case '+':
                result = operand_left + operand_right;
                break;
            case '-':
                result = operand_left - operand_right;
                break;
            case '*':
                result = operand_left * operand_right;
                break;
        }

        operands[operator_index] = result;
        operands.erase(operands.begin() + operator_index + 1);
        operators.erase(operators.begin() + operator_index);

        operator_count--;
    }
};

void solve(Expression expression, bool is_prev_bracket)
{
    if(expression.operator_count == 1)
    {
        expression.Calculate(0);
        max_result = max(max_result, expression.operands[0]);
        return;
    }

    {
        Expression new_expression(expression);
        new_expression.Calculate(0);
        solve(new_expression, false);
    }
    
    if(!is_prev_bracket)
    {
        Expression new_expression(expression);
        new_expression.Calculate(1);
        solve(new_expression, true);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string expression_str; 
    cin >> expression_str;

    if(n == 1)
    {
        cout << expression_str;
        return 0;
    }

    Expression expression(expression_str);
    solve(expression, false);

    cout << max_result;
}