#include <iostream>
#include <vector>

class Node
{
public:
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

void inOrder(Node *node, std::vector<int> res)
{
    if (node == nullptr)
        return;
    inOrder(node->left, res);
    res.push_back(node->data);
    inOrder(node->right, res);
}

void PreOrder(Node *node, std::vector<int> res)
{
    if (node == nullptr)
        return;

    res.push_back(node->data);
    PreOrder(node->left, res);
    PreOrder(node->right, res);
}

void PostOrder(Node *node, std::vector<int> res)
{
    if (node == nullptr)
        return;

    PostOrder(node->left, res);
    PostOrder(node->right, res);
    res.push_back(node->data);
}

void levelOrderTraveral(Node *root, int level, std::vector<std::vector<int>> &res)
{
    if (root == nullptr)
        return;
    if (res.size() <= level)
    {
        res.push_back({});
    }

    res[level].push_back(root->data);

    levelOrderTraveral(root->left, level + 1, res);
    levelOrderTraveral(root->right, level + 1, res);
}
// Function to perform level order traversal
std::vector<std::vector<int>> levelOrder(Node *root)
{

    // Stores the result level by level
    std::vector<std::vector<int>> res;

    levelOrderTraveral(root, 0, res);
    return res;
}

int main()
{
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    //  / \  /  \  / \
    //17 23 27 3  8  11
    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    std::vector<std::vector<int>> res = levelOrder(root);

    for (std::vector<int> level : res)
    {
        for (int val : level)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}