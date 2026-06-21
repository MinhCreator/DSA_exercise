#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int countNodes(Node *root)
{
    // Base case: empty tree has 0 nodes
    if (root == nullptr)
    {
        return 0;
    }

    // Total = 1 (current node) + left subtree nodes + right subtree nodes
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node *root)
{
    // Base case 1: empty tree
    if (root == nullptr)
    {
        return 0;
    }

    // Base case 2: node has no children (it's a leaf)
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    // Otherwise, sum the leaves from both subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

int treeHeight(Node *root)
{
    if (root == nullptr)
        return -1;

    int LeftHeight = treeHeight(root->left);
    int RightHeight = treeHeight(root->right);

    return std::max(LeftHeight, RightHeight) + 1;
}

int main()
{
    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    std::cout << treeHeight(root) << std::endl;
    std::cout << countLeaves(root) << std::endl;
    std::cout << countNodes(root) << std::endl;
}