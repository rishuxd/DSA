// *****pyara question

#include<iostream>
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

// iterative approach
// SC : O(1)
// TC : O(n)
void reverseList(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *prev = NULL;
    Node *forward = NULL;
    Node *curr = head;

    while (curr != NULL)
    {

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
}

// recursive but iterrative approach
// SC : O(n)
// TC : O(n)
void reverse(Node* &head, Node* curr, Node* prev){
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// 2nd recursive approach
// SC : O(n)
// TC : O(n)
Node* reverse1(Node* &head){
    //base case
    if (head == NULL || head->next)
    {
        return head;
    }
    Node* chhotahead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return chhotahead;
}

int main(){
    Node *head = NULL;
}