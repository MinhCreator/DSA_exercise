#include <iostream>

struct node
{
    char data;
    node *next;
};

void push(node **top, char data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

char pop(node **top)
{
    if (*top == NULL)
    {
        return -1;
    }
    char data = (*top)->data;
    node *temp = *top;
    *top = (*top)->next;
    delete temp;
    return data;
}

void is_empty(node *top)
{
    if (top == nullptr)
    {
        std::cout << "stack empty" << std::endl;
    }
    else
    {
        std::cout << "stack not empty" << std::endl;
    }
}

char peek(node *top)
{
    if (top == NULL)
        return '\0';
    return top->data;
}

void display(node *top)
{
    node *temp = top;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    node *top = NULL;
    std::string s, postfix = "";
    std::cin >> s;

    for (int i = 0; i < s.size(); i++)
    {

        if (isalnum(s[i]))
        {
            postfix += s[i];
        }

        else if (s[i] == '(')
        {
            push(&top, s[i]);
        }

        else if (s[i] == ')')
        {
            while (top != NULL && peek(top) != '(')
            {
                postfix += peek(top);
                pop(&top);
            }
            pop(&top);
        }

        else
        {
            while (top != NULL && precedence(peek(top)) >= precedence(s[i]))
            {
                postfix += peek(top);
                pop(&top);
            }
            push(&top, s[i]);
        }
    }

    while (top != NULL)
    {
        postfix += peek(top);
        pop(&top);
    }

    std::cout << postfix;
}