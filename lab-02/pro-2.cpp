#include <iostream>

using namespace std;

struct Node
{
    int num;
    int coeff;
    Node *next;
};

Node *createNode(int num, int coeff)
{
    Node *newNode = new Node;
    newNode->num = num;
    newNode->coeff = coeff;
    newNode->next = NULL;
    return newNode;
}

void inputPolynomial(Node **head)
{
    int n, coeff;
    cin >> n;
    while (n--)
    {
        cin >> coeff;
        Node *newNode = createNode(n, coeff);
        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            Node *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void printPolynomial(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->coeff != 0)
        {
            if (temp->coeff > 0)
            {
                cout << "+ " << temp->coeff << "x^" << temp->num;
            }
            else
            {
                cout << temp->coeff << "x^" << temp->num;
            }
        }
        temp = temp->next;
    }
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *temp1 = poly1;
    Node *temp2 = poly2;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1 != NULL)
        {
            sum += temp1->coeff;
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            sum += temp2->coeff;
            temp2 = temp2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        Node *newNode = createNode(temp1 != NULL ? temp1->num : temp2->num, sum);
        if (result == NULL)
        {
            result = newNode;
        }
        else
        {
            Node *temp = result;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return result;
}

void subtractPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *temp1 = poly1;
    Node *temp2 = poly2;
    int borrow = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int diff = borrow;
        if (temp1 != NULL)
        {
            diff -= temp2->coeff;
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            diff -= temp1->coeff;
            temp2 = temp2->next;
        }
        borrow = diff / 10;
        diff = diff % 10;
        Node *newNode = createNode(temp1 != NULL ? temp1->num : temp2->num, diff);
        if (result == NULL)
        {
            result = newNode;
        }
        else
        {
            Node *temp = result;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printPolynomial(result);
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    inputPolynomial(&poly1);
    inputPolynomial(&poly2);
    cout << "Polynomial 1: ";
    printPolynomial(poly1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2);
    Node *sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPolynomial(sum);
    subtractPolynomials(poly1, poly2);
    return 0;
}