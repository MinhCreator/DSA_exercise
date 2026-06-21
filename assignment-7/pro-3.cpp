#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *left, *right;

    Node(char x) : data(x), left(nullptr), right(nullptr) {}
};

bool isOpearator(char x){
    switch (x){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return true;
    }
    return false;
}

string preToInfix(string pre_exp){

    stack<string> s;

    int length = pre_exp.size();

    for (int i = length - 1; i >= 0; i--){

        if (isOpearator(pre_exp[i])) {

            string op1 = s.top();
            s.pop();

            string op2 = s.top();
            s.pop();

            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            s.push(temp);
        }
        else {
            int index = 1;
            s.push(string(index, pre_exp[i]));
        }
    }

    return s.top();
}

Node* buildTree(string s){

    stack<Node*> st;

    for (int i = s.size() - 1; i >= 0; i--){

        char c = s[i];

        Node* node = new Node(c);

        if (!isOpearator(c)){
            st.push(node);
        }
        else{

            Node* left = st.top();
            st.pop();

            Node* right = st.top();
            st.pop();

            node->left = left;
            node->right = right;

            st.push(node);
        }
    }

    return st.top();
}

void inorder(Node* root){

    if (root == nullptr) return;

    inorder(root->left);

    cout << root->data;

    inorder(root->right);
}

int main(){

    string s;
    cin >> s;

    cout << preToInfix(s) << endl;

    Node* root = buildTree(s);

    inorder(root);

    return 0;
}