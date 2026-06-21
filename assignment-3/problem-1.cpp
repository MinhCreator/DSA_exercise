/**
 * @brief Inserts a node at the beginning of a linked list.
 * @param head The head node of the linked list.
 * @param data The data to be inserted.
 */
#include <iostream>


struct node
{
    int data;
    node *next;
};

void insert_begin(node *head, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

/**
 * @brief Inserts a node at the end of a linked list.
 * @param head The head node of the linked list.
 * @param data The data to be inserted.
 */
void insert_end(node *head, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head = temp;
}

/**
 * @brief Deletes the first node of a linked list.
 * @param head The head node of the linked list.
 * @return The updated head node.
 */
node *del_first(node *head)
{
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

/**
 * @brief Deletes the last node of a linked list.
 * @param head The head node of the linked list.
 * @return The updated head node.
 */
node *del_end(node *head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    head = temp;
    return head;
}

/**
 * @brief Prints the elements of a linked list.
 * @param head The head node of the linked list.
 */
void print(node *head)
{
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

/**
 * @brief Counts the number of elements in a linked list.
 * @param head The head node of the linked list.
 */
void count_value(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    std::cout << "Count: " << count << std::endl;
}

/**
 * @brief Searches for a value in a linked list.
 * @param head The head node of the linked list.
 * @param target_value The value to be searched for.
 */
void search_value(node *head, int target_value)
{

    while (head != NULL)
    {
        if (head->data == target_value)
        {
            std::cout << "Found" << std::endl;
            return;
        }
        head = head->next;
    }
}

/**
 * @brief Searches for a node at a given position in a linked list.
 * @param head The head node of the linked list.
 * @param position The position of the node to be searched for.
 * @return The searched node if found, nullptr otherwise.
 */
node *search_position(node *head, int position)
{
    int count = 0;
    node *curr = head;
    while (curr != nullptr)
    {
        if (count == position)
        {
            return curr;
        }
        count++;
        curr = curr->next;
    }
    return nullptr;
}

/**
 * @brief Deletes a node at a given position in a linked list.
 * @param head The head node of the linked list.
 * @param position The position of the node to be deleted.
 * @return The updated head node.
 */
node *del_position(node *head, int position)
{
    int count = 0;

    if (position == 0)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node *curr = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (curr->next == nullptr)
        {
            return head; // Position out of range
        }
        curr = curr->next;
    }

    node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

/**
 * @brief Inserts a node at a given position in a linked list.
 * @param head The head node of the linked list.
 * @param position The position of the node to be inserted.
 * @param data The data to be inserted.
 * @return The updated head node.
 */
node *insert_position(node *head, int position, int data)
{
    if (position == 0)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = head;
        return temp;
    }
    node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (current->next == nullptr)
        {
            return head; // Position out of range
        }
        current = current->next;
    }
    node *temp = new node();
    temp->data = data;
    temp->next = current->next;
    current->next = temp;
    return head;
}

/**
 * @brief Appends a linked list to the end of another linked list.
 * @param p1 The first linked list.
 * @param p2 The second linked list.
 * @return The updated first linked list.
 */
node *append_node(node *p1, node *p2)
{
    while (p1->next != nullptr)
    {
        p1 = p1->next;
    }
    p1->next = p2;
    return p1;
}

/**
 * @brief Merges two sorted linked lists.
 * @param p1 The first linked list.
 * @param p2 The second linked list.
 * @return The merged linked list.
 */
node *mergeLists(node *p1, node *p2)
{
    node *dummy = new node(); // Dummy node to hold the merged list
    node *current = dummy;    // Current node in the merged list
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->data < p2->data)
        {
            current->next = p1;
            p1 = p1->next;
        }
        else
        {
            current->next = p2;
            p2 = p2->next;
        }
        current = current->next;
    }
    current->next = p1 ? p1 : p2; // Append remaining nodes from p1 or p2
    return dummy->next;
}

/**
 * @brief Creates a new node with the given data.
 * @param data The data to be stored in the node.
 * @return The newly created node.
 */
node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int main()
{
    node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    node *mode = del_position(head, 2);
    // print(mode);

    node *mod = insert_position(mode, 2, 100);
    print(mod);
    return 0;
}