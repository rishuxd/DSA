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
            next = NULL;
        }
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};


// insert at any position
void insertNode(Node *&tail, int element, int data)
{
    Node *nodeToInsert = new Node(data);
    // empty list
    if (tail == NULL)
    {
        tail = nodeToInsert;
        nodeToInsert->next = nodeToInsert;
    }
    else{
        // non-empty list
        Node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // ----------------------------
        nodeToInsert->next = tail;
        curr->next = nodeToInsert;
    }
}


// delete node
void deleteNode(Node* &tail, int element){
    // empty list
    if (tail == NULL){
        cout<<"List is already empty."<<endl;
        return;
    }
    else{
        // non-empty list
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // single element list
        if (curr == prev){
            tail = NULL;
        }
        // >= 2 node list
        if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
    
}
// is circular or not
bool isCircular(Node *head){
    // empty list
    if (head == NULL)
    {
        return NULL;
    }
    // non-empty list
    Node *temp = head->next;
    while (temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head)
       return true;
    if(temp == NULL){
        return false;
    }
}

// printing Linked List
void print(Node * &tail)
{
    Node *temp = tail;
    if (tail == NULL){
        cout<<"Linked List is empty."<<endl;
        return;
    }
    do{
        cout << tail->data << " ";
        tail = tail->next;
    }
    while (tail != temp);
    cout<<endl;
}

int main()
{
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    cout<<"Data at Tail : "<<tail->data<<endl;
    insertNode(tail, 3, 46);
    print(tail);
    cout << "Data at Tail : " << tail->data << endl;
    insertNode(tail, 46, 100);
    print(tail);
    cout << "Data at Tail : " << tail->data << endl;
    deleteNode(tail, 3);
    print(tail);
    cout << "Data at Tail : " << tail->data << endl;
    if(isCircular){
        cout<<"Circular in nature."<<endl;
    }
    else{
        cout<<"Linked list is not Circular"<<endl;
    }
}