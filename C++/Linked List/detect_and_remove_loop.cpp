// *****pyara question
// loop detect karne ke 3 ways hai , SEARCH FOR IT
// cycle delete karne ke 5 ways hai , don't worry jo padha hai vo sabse OPTIMISED hai

#include <iostream>
#include<map>
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

// is looped or not
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;

    Node* temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next; 
    }
    return false;
}

// is looped or not *another approach
// Floyd's detection method
// Algo in DSA WhatsApp group
// TC: O(n)
// SC: O(1)
Node* flyodDetectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        // condition is reached or not
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

// gives starting node of the cycle
Node* getStartCycleNode(Node* head){
    if (head == NULL)
    {
        return NULL;
    }
    Node* intersection = flyodDetectLoop(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// deleting loop
Node* deleteLoop(Node* head){
    if (head == NULL)
    {
        return NULL;
    }
    Node* start = getStartCycleNode(head);
    if (start == NULL)
    {
        return head;
    }
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;   
    return head; 
}

int main()
{
}