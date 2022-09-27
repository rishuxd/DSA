#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<" ."<<endl;
    }
};

// inserting at Head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // new node creation
    Node* temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

// insert at Tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node* temp = new Node(data);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

//insert at any position
void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    // inserting at 1st position
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }
    // creating a node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// deleting node
void deleteNode(Node *&head, Node *&tail, int position)
{
    // delete 1st Node
    if(position == 1){
        Node* temp = head;
        head=head->next;
        temp->next = NULL;
        delete temp;
    }
    // deleting any other node or last node
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        if (curr->next == NULL){
            prev->next = curr->next;
            delete curr;
            tail = prev;
        }
        else{
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
            
    }
}

// check palindrome
bool isPalindrome(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0;

    int e = arr.size() - 1;

    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

// printing Linked List
void printLinkedList(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    // created a new Node
    // Node* node1 = new Node(10);

    // head pointed to node1
    Node* head = NULL;
    Node* tail = NULL;
    printLinkedList(head);

    // inserting new node
    insertAtHead(head, tail, 12);
    printLinkedList(head);

    // inserting new node
    insertAtTail(head, tail, 15);
    printLinkedList(head);

    // inserting at 2nd position
    insertAtPosition(head, tail, 3, 2);
    printLinkedList(head);

    // inserting at 1st position by insertAtPosition function
    insertAtPosition(head, tail, 1, 45);
    printLinkedList(head);

    // inserting at 1st position by insertAtPosition function
    insertAtPosition(head, tail, 5, 100);
    printLinkedList(head);

    // delete 1st node
    deleteNode(head, tail, 1);
    printLinkedList(head);

    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    // deleteing 3rd node
    deleteNode(head, tail, 2);
    printLinkedList(head);

    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    // deleteing last node
    deleteNode(head, tail, 3);
    printLinkedList(head);

    cout<<"Data at Head : "<<head->data<<endl;
    cout<<"Data at Tail : "<<tail->data<<endl;

    insertAtHead(head, tail, 2);
    printLinkedList(head);

    cout << "Data at Head : " << head->data << endl;
    cout << "Data at Tail : " << tail->data << endl;

    // check palindrome
    cout<<isPalindrome(head)<<endl;
}