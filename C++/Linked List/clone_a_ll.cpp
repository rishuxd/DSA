// pyara question

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arb;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
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


// Approach 1
// TC: O(n)
// SC: O(n)

// Step 1 -> create a clone list using random pointer
// Step 2 -> copy random pointer using mapping -> cloneNode->random = mapping[originalNode->random]

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *copyList(Node *head)
{
    // step 1 -> create a clone list using next pointers
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 -> create a map and place random pointers

    unordered_map<Node *, Node *> oldToNewNode;

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode != NULL)
    {
        cloneNode->arb = oldToNewNode[originalNode->arb];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

// Approach  (map hatao, links change karo)
// TC: O(n)
// SC: O(1)

// step 1: create a clone lsit
// step 2; add link in-between originalnode and clonenode
// step 3: copy random pointer -> temp->next->random = temp->random->next
// step 4: revert changes done in step 2
// step 4: return anshead

Node *copyList(Node *head)
{
    // step 1 -> create a clone list using next pointers
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // step 2 -> clonenodes add in-between original list
    Node *originalnode = head;
    Node *clonenode = clonehead;

    while (originalnode != NULL && clonenode != NULL)
    {
        Node *next = originalnode->next;
        originalnode->next = clonenode;
        originalnode = next;

        next = clonenode->next;
        clonenode->next = originalnode;
        clonenode = next;
    }

    // step 3 -> random pointer copy
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            if (temp->arb != NULL)
            {
                temp->next->arb = temp->arb->next;
            }
            else
            {
                temp->next->arb = temp->arb;
            }
        }
        temp = temp->next->next;
    }

    // step 4 -> revert changes done in step 2
    originalnode = head;
    clonenode = clonehead;

    while (originalnode != NULL && clonenode != NULL)
    {
        originalnode->next = clonenode->next;
        originalnode = originalnode->next;

        if (originalnode != NULL)
        {
            clonenode->next = originalnode->next;
            clonenode = clonenode->next;
        }
    }

    // step 5 -> return clonehead
    return clonehead;
}