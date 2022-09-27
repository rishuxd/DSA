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

// intution approach (fails if data replacement is not allowed)
Node* sortList(Node * head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (zeroCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (zeroCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

// better method
// TC: O(n)
// SC: O(1)

// make three different ll of 0s, 1s & 2s and merge them in a single list
// dummy nodes are important to minimise the use of conditions, warna if-else lagate lagate thak jaoge


// inserting at tail
void insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}

Node *sortList1(Node *head)
{
    Node* zeroHead = new Node(-1); // dummy node, pointing it as head
    Node* zeroTail = zeroHead; // tail for the ease of insertion
    Node* oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // create separate list 0s, 1s and 2s
    Node* curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        
        if(value == 0){
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    // merge sublists
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setting head
    head = zeroHead->next;

    // delete dummy nodes
    delete oneHead;
    delete twoHead;
    delete twoHead;

    return head;
}

int main()
{
}