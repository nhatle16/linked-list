#include <iostream>
using namespace std;

// stack setting with array 
int a[10000], maxN = 10000;
int n = 0;

void push(int x){
    if (n == maxN)  return;
    a[n] = x;
    ++n;
}

void pop(){
    if (n >= 1){
        --n;
    }
}

int top(){
    return a[n-1];
}

int size(){
    return n;
}

// stack setting with linked list
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

void printList(node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int countNode(node* head){
    int cnt = 0;
    while (head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void pushFront(node*& top, int x){
    node* newNode = makeNode(x);
    if (top == NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void popFront(node*& top){
    if (top != NULL){
        node* temp = top;
        top = top->next;
        delete temp;
    }
}

int topNode(node* top){
    if (top != NULL){
        return top->data;   
    }
}




