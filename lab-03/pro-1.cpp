#include <iostream>
#include <stack>

struct Node {
    char data;
    Node *next;
};

Node* init_stack(){
    return nullptr;
}

bool isEmpty_(Node *top){
    return top == nullptr;
}

void push(Node **top, char data){
    Node * newTemp = new Node();
    newTemp->data = data;
    newTemp->next = *top;
    *top = newTemp;
}

char pop(Node **top){
    if (isEmpty_(*top))
    {
        return -1;
    }
    char data = (*top)->data;
    Node *temp = *top;
    *top = (*top)->next;
    delete temp;
    return data;
}

// convert from infix to postfix
int operatorPrecedence(char op){
    if (op == '+' || op == '-'){
        return 1;
    }
    if (op == '*' || op == '/'){
        return 2;
    }
    return 0;
}

std::string infixToPostfix(std::string infix){
    std::stack<char> st;
    std::string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char character = infix[i];

        if (isalnum(character))
        {
            postfix += character;
        }
        else if (character == '('){
            st.push(character);
        }
        else if (character == ')'){
          while (st.top() != '('){
              postfix += st.top();
              st.pop();

          }
          st.pop();
        }
        else {
            while (!st.empty() && operatorPrecedence(character) <= operatorPrecedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(character);
            
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}


int main() {
    std::cout << infixToPostfix("A+(B-C)");
}