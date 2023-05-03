#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* makeNode(int x){
    node* newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void printList(node*& head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int countNode(node*& head){
    int count = 0;
    while (head != NULL){
        ++count;
        head = head->next;
    }
}

void pushFront(node*& head, int x){
    node* newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void pushBack(node*& head, int x){
    node* newNode = makeNode(x);
    if (head == NULL){
        head = newNode;
    }
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertNode(node*& head, int k, int x){
    node* newNode = makeNode(x);
    int size = countNode(head);
    if (head == nullptr){
        head = newNode;
        return;
    }
    node* temp = head;
    if (k < 1 || k > size+1)    return;
    if (k == 1){
        pushFront(head, x);
        return;
    }
    for (int i = 1; i <= k-2; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void popFront(node*& head){
    if (head == NULL)   return;
    node* temp = head;
    head = head->next;
    delete temp;
}

void popBack(node*& head){
    if (head == NULL)   return;
    node* temp = head;
    if (temp->next == NULL){
        head = NULL;
        return;
    }
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    node* last = temp->next;
    temp->next = NULL;
    delete last;
}

void popNode(node*& head, int k, int x){
    int size = countNode(head);
    if (k < 1 || k > size)   return;
    if (k == 1){
        popFront(head);
        return;
    }
    else {
        node* temp = head;
        for (int i = 1; i <= k-2; i++){
            temp = temp->next;
        }
        node* kth = temp->next;
        temp->next = kth->next;
        delete kth;
    }   
}

void insertNodeBFVL(node*& head, int k, int x){
    if (head == NULL)   return;
    node* temp = head;
    node* newNode = makeNode(x);
    while (temp->next->data != k){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertNodeAFVL(node*& head, int k, int x){
    if (head == NULL)   return;
    node* temp = head;
    node* newNode = makeNode(x);
    while (temp->data != k){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void popNodeBFVL(node*& head, int k){
    if (head == NULL)   return;
    node* temp = head;
    if (head->data == k)   return;
    if (head->next->data == k){
        node* first = head;
        head = head->next;
        delete first;
        return;
    }
    while (temp->next->next->data != k){
        temp = temp->next;
    }
    node* after = temp->next;
    temp->next = after->next;
    delete after;
}

void popNodeAFVL(node*& head, int k){
    if (head == NULL)   return;
    node* temp = head;
    while (temp->data != k){
        temp = temp->next;
    }
    node* after = temp->next;
    if (after == NULL)  return;
    temp->next = after->next;
    delete after;
}


void popIden(node*& head, int k){
    if (head == nullptr)    return;
    node* cur = head;
    if (cur->data == k){
        cur == nullptr;
    }
    while (cur->next != nullptr){
        if (cur->data == k){
            node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
}

void interchange(node*& head, int x){
    node* newNode = new node;
    if (head == nullptr){
        head = newNode;
        return;
    }
    node* prev = head;
    node* temp = head->next;
    while (prev->next->data != x && prev->next != nullptr){
        prev = prev->next;
    }
    if (prev->next == nullptr)   return;
    node* cur = prev->next;
    node* after = cur->next;
    prev->next = head;
    head->next = after;
    cur->next = temp;
    head = cur;    
}

int main(){

}
