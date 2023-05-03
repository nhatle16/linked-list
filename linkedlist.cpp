#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addNode(Node*& head, int data)
{
    Node* newNode = createNode(data);
    if (head == nullptr)
        head = newNode;
    else
    {
        Node* cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

void printList(Node* head)
{
    Node* cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* reverse(Node* head)
{
    
    Node* prev_node = nullptr;
    Node* curr_node = head;
    Node* next_node = nullptr;
    
    while (curr_node != nullptr)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    
    return prev_node;
}

bool checkPalindrome(Node* head)
{
   if (head == nullptr) {
        return false;
    }
    Node* newHead = new Node{head->data};
    Node* curr = head->next;
    Node* newCurr = newHead;
    while (curr != nullptr) {
        newCurr->next = new Node{curr->data};
        curr = curr->next;
        newCurr = newCurr->next;
    }
    Node* prev_node = reverse(newHead);

    while (prev_node && head)
    {
        if (prev_node->data != head->data)
            return false;
        prev_node = prev_node->next;
        head = head->next;
    }
     
     return true;
}
int main()
{
    Node* head = nullptr;
    int numNodes, data;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++)
    {
        cout << "Enter data for node " << i + 1 << " : ";
        cin >> data;
        addNode(head, data);
    }

    cout << "The linked list is: ";
    printList(head);
    //Node* head1 = head;
    //printList(head1);

    if (checkPalindrome(head) == true)
        cout << "\nThis linked list is palindrome!";
    else
        cout << "\nThis linked list is not palindrome!";

    return 0;
}