#include <iostream>
#include <stack>

std::string parentheseChecker(std::string exp)
{
    std::stack<char> parent_stack;
    std::string allMatched = "the expression has parentheses that is matched";

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            parent_stack.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (parent_stack.empty())
            {
                return "the expression has parentheses that is not matched";
            }
            else if ((exp[i] == ')' && parent_stack.top() == '(') ||
                     (exp[i] == '}' && parent_stack.top() == '{') ||
                     (exp[i] == ']' && parent_stack.top() == '['))
            {
                parent_stack.pop();
            }
            else
            {
                return "the expression has parentheses that is not matched";
            }
        }
    }

    if (!parent_stack.empty())
    {
        allMatched = "the expression has parentheses that is not matched";
    }

    return allMatched;
}

int main()
{
    std::cout << parentheseChecker("{A+(B-C)}");
}