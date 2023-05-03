#include <iostream>
using namespace std;

// queue setting with array
int a[10000], maxN = 10000;
int n = 0;

bool empty(){
    return n == 0;
}
void push(int x){
    if (n == maxN)  return; 
    a[n] = x;
    ++n;
}

void pop(){
    if (n == 0) return;
    for (int i = 0; i < n-1; i++){
        a[i] = a[i+1];
    }
    --n;
}

int first(){
    return a[0];
}

int size(){
    return n;
}

// queue setting with linked list

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

int countNode(node* head){
    int cnt;
    while (head->next != nullptr){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void printList(node* head){
    while (head->next != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void pushBack(node*& queue, int x){
    node* newNode = makeNode(x);
    if (queue == nullptr){
        queue = newNode;
        return;
    }
    node* temp = queue;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void popFront(node*& queue){
    if (queue == nullptr)   return;
    node* temp = queue;
    queue = queue->next;
    delete temp;
}

bool check(node* queue){
    return queue == nullptr;
}