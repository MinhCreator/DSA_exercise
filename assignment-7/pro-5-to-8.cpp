#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to find the minimum value node in a tree (In-order Successor)
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// BST Insertion
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    // Standard BST rule: duplicates can go to the right or left (we'll use right here)
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// BST Deletion
Node* remove(Node* root, int val) {
    if (root == nullptr) return root;

    if (val < root->data) {
        root->left = remove(root->left, val);
    } else if (val > root->data) {
        root->right = remove(root->right, val);
    } else {
        // Node found: Handle the 3 deletion cases
        
        // Case 1 & 2: Leaf node or node with only one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy successor's value to this node
        root->right = remove(root->right, temp->data); // Delete the successor
    }
    return root;
}

// Traversals
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Level-Order (Breadth-First) Traversal to verify structures
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

void solveProblem5() {
    cout << "--- Problem 5 ---" << endl;
    Node* root = nullptr;
    // Constructing the original tree structure from page 2 image
    int initialElements[] = {42, 12, 53, 8, 16, 60, 2, 22, 57, 65, 19};
    for (int x : initialElements) root = insert(root, x);

    // a. Add node 9
    root = insert(root, 9);
    cout << "After adding 9 (In-order): "; inOrder(root); cout << endl;

    // b. Remove node 12
    root = remove(root, 12);
    cout << "After removing 12 (Level-order): "; levelOrder(root);

    // c. Remove node 53
    root = remove(root, 53);
    cout << "After removing 53 (Level-order): "; levelOrder(root);
}

void solveProblem6() {
    cout << "\n--- Problem 6 ---" << endl;
    Node* root = nullptr;
    vector<int> initial = {98, 2, 48, 12, 56, 32, 4, 67, 23, 87, 23, 55, 46};
    for (int x : initial) root = insert(root, x);
    
    // a. Insert elements
    vector<int> toInsert = {21, 39, 45, 54, 63};
    for (int x : toInsert) root = insert(root, x);
    cout << "After additions (In-order): "; inOrder(root); cout << endl;

    // b. Delete elements
    vector<int> toDelete = {23, 56, 2, 45};
    for (int x : toDelete) root = remove(root, x);
    cout << "After deletions (In-order): "; inOrder(root); cout << endl;
}

Node* buildOriginalTree7() {
    Node* root = nullptr;
    int items[] = {42, 12, 53, 8, 16, 60, 2, 22, 57, 65, 19};
    for (int x : items) root = insert(root, x);
    return root;
}

void solveProblem7() {
    cout << "\n--- Problem 7 ---" << endl;
    Node* root = nullptr;

    // a. Remove 65
    root = buildOriginalTree7();
    root = remove(root, 65);
    cout << "a. Remove 65 (Level-order): "; levelOrder(root);

    // b. Remove 16
    root = buildOriginalTree7();
    root = remove(root, 16);
    cout << "b. Remove 16 (Level-order): "; levelOrder(root);

    // c. Remove 12
    root = buildOriginalTree7();
    root = remove(root, 12);
    cout << "c. Remove 12 (Level-order): "; levelOrder(root);

    // d. Remove 42 (Root deletion)
    root = buildOriginalTree7();
    root = remove(root, 42);
    cout << "d. Remove 42 (Level-order): "; levelOrder(root);
}

void solveProblem8() {
    cout << "\n--- Problem 8 ---" << endl;
    Node* root = nullptr;
    // Constructing the tree from the shaded diagram
    int elements[] = {45, 39, 56, 12, 54, 78, 10, 34, 67, 89, 32, 81};
    for (int x : elements) root = insert(root, x);

    // a. Traversals
    cout << "a. Pre-order:  "; preOrder(root); cout << endl;
    cout << "   In-order:   "; inOrder(root); cout << endl;
    cout << "   Post-order: "; postOrder(root); cout << endl;

    // b. Delete root node (45)
    root = remove(root, 45);
    cout << "b. After deleting root 45 (Level-order): "; levelOrder(root);

    // c. Insert elements
    vector<int> extra = {11, 22, 33, 44, 55, 66, 77};
    for (int x : extra) root = insert(root, x);
    cout << "c. After adding elements (In-order): "; inOrder(root); cout << endl;
}

int main() {
    solveProblem5();
    solveProblem6();
    solveProblem7(); // Swapped layout order matches file presentation flow
    solveProblem8();
    return 0;
}
