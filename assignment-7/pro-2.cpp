#include <iostream>
#include <vector>

class Node
{
public:
    std::string data;
    Node *left;
    Node *right;
    Node(std::string value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void inOrder(Node *node, std::vector<std::string> res)
{
    if (node == nullptr)
        return;
    inOrder(node->left, res);
    res.push_back(node->data);
    inOrder(node->right, res);
}
// case a
std::string getInfix(Node *root)
{
    if (root == nullptr)
        return "";

    // If it's a leaf node (operand), just return its value
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }

    // If it's an operator node, wrap its sub-expressions in parentheses
    return "(" + getInfix(root->left) + " " + root->data + " " + getInfix(root->right) + ")";
}

// case b
void printPrefix(Node *root)
{
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(Node *root)
{
    if (root == nullptr)
        return;
    printPostfix(root->left);
    printPostfix(root->right);
    std::cout << root->data << " ";
}

// case c
int getVariableValue(std::string var)
{
    if (var == "a")
        return 30; // Values given in assignment
    if (var == "b")
        return 10;
    if (var == "c")
        return 2;
    if (var == "d" || var == "D")
        return 30;
    if (var == "e")
        return 10;
    return std::stoi(var); // If it's already a raw number string
}

int evaluate(Node *root)
{
    if (root == nullptr)
        return 0;

    // Leaf node: return its numerical value
    if (root->left == nullptr && root->right == nullptr)
    {
        return getVariableValue(root->data);
    }

    // Evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Apply the current node's operator
    if (root->data == "+")
        return leftVal + rightVal;
    if (root->data == "-")
        return leftVal - rightVal;
    if (root->data == "*")
        return leftVal * rightVal;
    if (root->data == "/")
        return leftVal / rightVal;

    return 0;
}

int main()
{
    Node *root = new Node("+");
    root->left = new Node("e");
    root->right = new Node("-");
    root->right->left = new Node("D");
    root->right->right = new Node("*");
    root->right->right->left = new Node("/");
    root->right->right->right = new Node("c");
    root->right->right->left->left = new Node("a");
    root->right->right->left->right = new Node("b");

    // a. Extract Infix
    std::cout << "Infix: " << getInfix(root) << std::endl;

    // b. Extract Prefix & Postfix
    std::cout << "Prefix: ";
    printPrefix(root);
    std::cout << "\nPostfix: ";
    printPostfix(root);
    std::cout << std::endl;

    // c. Evaluate
    std::cout << "Evaluation Result: " << evaluate(root) << std::endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;
}