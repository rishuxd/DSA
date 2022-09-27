#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};

// Approach
// step 1 -> find mid
// step 2 -> break into halves
// step 3 -> recursively sort both halves
// step 4 -> merge sorted lls
// step 5 -> return sorted ll

// finding mid of ll
node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// merging two ll
node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

// mergeSort function
node *mergeSort(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // finding mid
    node *mid = findMid(head);
    // splitting into two halves
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;
    // recursive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    // merge both halves
    node *result = merge(left, right);

    return result;
}