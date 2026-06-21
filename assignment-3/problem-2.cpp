/**
 * @file problem-2.cpp
 * @brief This file contains the implementation of
 * several functions related to linked lists.
 */
#include <iostream>

using namespace std;

/**
 * @brief A struct to represent a node in a linked list.
 * @struct node
 * @var data The data stored in the node.
 * @var next The next node in the linked list.
 */
struct node
{
    int data;
    node *next;
};

/**
 * @brief Checks if a given set s is a subset of set head.
 * @param s The set to be checked.
 * @param head The head node of the set.
 * @return true if s is a subset of head, false otherwise.
 */
bool isset(node *s, node *head)
{
    node *curr = s;
    while (curr != nullptr)
    {
        bool found = false;
        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == curr->data)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

/**
 * @brief Checks if set s1 is a subset of set s2.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return true if s1 is a subset of s2, false otherwise.
 */
bool subset(node *s1, node *s2)
{
    node *curr1 = s1;
    while (curr1 != nullptr)
    {
        bool found = false;
        node *curr2 = s2;
        while (curr2 != nullptr)
        {
            if (curr2->data == curr1->data)
            {
                found = true;
                break;
            }
            curr2 = curr2->next;
        }
        if (!found)
        {
            return false;
        }
        curr1 = curr1->next;
    }
    return true;
}

/**
 * @brief Computes the union of two sets represented as linked lists.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return The head node of the set representing the union of s1 and s2.
 */
node *unionSet(node *s1, node *s2)
{
    node *result = nullptr;
    node *curr1 = s1;
    while (curr1 != nullptr)
    {
        result = insert_end(result, curr1->data);
        curr1 = curr1->next;
    }
    node *curr2 = s2;
    while (curr2 != nullptr)
    {
        result = insert_end(result, curr2->data);
        curr2 = curr2->next;
    }
    return result;
}

/**
 * @brief Computes the intersection of two sets represented as linked lists.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return The head node of the set representing the intersection of s1 and s2.
 */
node *intersection(node *s1, node *s2)
{
    node *result = nullptr;
    node *curr1 = s1;
    while (curr1 != nullptr)
    {
        bool found = false;
        node *curr2 = s2;
        while (curr2 != nullptr)
        {
            if (curr2->data == curr1->data)
            {
                found = true;
                break;
            }
            curr2 = curr2->next;
        }
        if (found)
        {
            result = insert_end(result, curr1->data);
        }
        curr1 = curr1->next;
    }
    return result;
}

/**
 * @brief Inserts a node at the end of a linked list.
 * @param head The head node of the linked list.
 * @param data The data to be inserted.
 * @return The updated head node.
 */
node *insert_end(node *head, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr)
    {
        return temp;
    }
    else
    {
        node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    }
}

/**
 * @brief Prints the elements of a linked list.
 * @param head The head node of the linked list.
 */
void print(node *head)
{
    node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

/**
 * @brief The main function of the program.
 * @return An integer value representing the exit status of the program.
 */
int main()
{
    return 0;
}
