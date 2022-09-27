#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};

int getLength(Node* &head){
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void printLinkedList(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if(tail == NULL){
        tail = temp;
        head = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void inserAtPosition(Node *&head, Node *&tail, int position, int data){
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position -1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp ->next = nodeToInsert; 
    temp->next->prev = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int position){
    if (position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL){
            curr->prev = NULL;
            prev->next = curr->next;
            delete curr;
            tail = prev;
        }
        else{
            curr->prev = NULL;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
            
    }
    
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 12);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    insertAtTail(head , tail, 8);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    inserAtPosition(head, tail, 1, 0);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    inserAtPosition(head, tail, 3, 16);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    inserAtPosition(head, tail, 5, 100);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    deleteNode(head, tail, 1);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    deleteNode(head, tail, 2);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    deleteNode(head, tail, 3);
    printLinkedList(head);
    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    return 0;
}
