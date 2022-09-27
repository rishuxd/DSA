//pyaara question

#include <iostream>
#include <vector>
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

// LL 1: 3->4->NULL
// LL 2: 2->3->0->NULL
// Output LL: 2->6->4->NULL
// TC: O(n+m)
// TC: O(max(n,m))

// Approach
// Step 1-> reverse both linked lists
// Step 2-> add them to a new linked list
// Step 3-> reverse the formed ll

// reverse function
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// insert function
void insertAtTail(struct Node* &head, struct Node* &tail, int val){
    Node *temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
    
// add function
struct Node *add(struct Node *first, struct Node *second)
{
    // Approach
    // 1-> carry = 0
    // 2-> sum find
    // 2-> digit find -> digit = sum%10
    // 2-> create node for digit
    // 2-> find carry -> carry = sum/10

    Node *anshead = NULL;
    Node *anstail = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);

        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }
    return anshead;
}

// main fuction
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // step 1 -> reverse input linked lists
    first = reverse(first);
    second = reverse(second);

    // step 2 -> add them
    Node *ans = add(first, second);

    // reverse the added list
    ans = reverse(ans);

    return ans;
}