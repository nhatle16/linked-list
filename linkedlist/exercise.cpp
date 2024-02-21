#include <iostream>
#include <iomanip>

using namespace std;

struct node{
    int data;
    node* next;
};

node* makeNode(int x){
    node* newNode = new node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void printList(node* head){
    node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int countNode(node* head){
    node* temp = head;
    int count = 0;
    while (temp->next != nullptr){
        ++count;
        temp = temp->next;
    }
    return count;
}

void deleteX(node*& head, int x){
    if (head == nullptr)    return;
    node* cur = head;
    if (cur->data == x){
        cur == nullptr;
    }
    while (cur->next != nullptr){
        if (cur->data == x){
            node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
}

void deleteIden(node*& head){
    if (head == nullptr || head->next == nullptr)    return;
    node* cur = head;
    while (cur != nullptr){
        node* temp = cur->next;
        node* prev = cur;
        while (temp != nullptr){
            if (cur->data == temp->data){
                prev->next = temp->next;
                delete temp;
                temp = cur->next;
            } 
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        cur = cur->next;        
    }
}


void pushFront(node*& head, int x){
    node* newNode = makeNode(x);
    if (head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void pushBack(node*& head, int x){
    node* newNode = makeNode(x);
    if (head == nullptr){
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertNode(node* head, int x, int k){
    node* newNode = makeNode(x);
    int size = countNode(head);
    if (head == nullptr){
        head = newNode;
        return;
    }
    node* temp = head;
    if (k < 1 || k > size + 1)  return;
    if (k == 1){
        pushFront(head, x);
        return;
    }
    for (int i = 1; i < k-2; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void reverseList(node*& head){
    node* cur = head;
    node* follow = nullptr;
    node* prev = nullptr;
    while (cur != nullptr){
        follow = cur->next; 
        cur->next = prev;
        prev = cur;
        cur = follow;
    }
    head = prev;
}

void insertEven(node*& head){
    if (head == nullptr){
        head = new node;
        head->data = 2;
        head->next = nullptr;
        return;
    }
    int x = 2;
    node* newNode = new node;
    newNode->next = head;
    newNode->data = x;
    head = newNode;
    node* after = head->next;
    while (after->next != nullptr){
        x = x + 2;
        node* even = new node;
        even->data = x;
        even->next = after->next;
        after->next = even;
        after = after->next->next;
    }
}

void sorted(node*& head){
    if (head == nullptr)    return;
    node* cur = head;
    while (cur != nullptr){
        node* minNode = cur;
        while (minNode->next != nullptr){
            node* temp = minNode->next;
            if (temp->data < minNode->data){
                int value = temp->data;
                temp->data = minNode->data;
                minNode->data = value;
            }
            else {
                minNode = minNode->next;
            }
        }
        cur = cur->next;
    }
}

node* sumAdjacent(node* head){
    if (head == nullptr)    return nullptr;
    node* head2 = nullptr;
    node* temp = head;    
    int sum = 0;
    while(temp != nullptr){
        sum += temp->data;
        pushBack(head2, sum);
        temp = temp->next;
    }
    return head2;
}

int main(){
    node* head = nullptr;
    int data;
    for (int i = 1; i <= 5; i++){
        cin >> data;
        pushBack(head, data);
    }
    /*int k, newdata;
    cin >> newdata >> k;
    insertNode(head, newdata, k);
    sorted(head);*/
    node* head2 = sumAdjacent(head);
    printList(head2);
    return 0;
}