// *****pyara question

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
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

// CodeStudio
// SC: O(n)
// TC: O(n)
Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    // step  1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    // step2: recursion dekh lega aage ka
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    // step3: return head of returned list
    return prev;
}

int main()
{

}