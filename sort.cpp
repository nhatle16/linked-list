#include <iostream>
#include <iomanip>
using namespace std;

struct svien{
    string name;
    double gpa;
    svien(){

    }
    svien(string ten, double diem){
        name = ten;
        gpa = diem;
    }
};

struct node{
    svien data;
    node* next;
};

node* makeNode(svien stu){
    node* newNode = new node;
    newNode->data = stu;
    newNode->next = NULL;
    return newNode;
}

void printList(node*& head){
    node* temp = head;
    while (temp != NULL){
        cout << temp->data.name << " " << fixed << setprecision(2) << temp->data.gpa << endl;
        temp = temp->next;
    }
    cout << endl;
}

int countNode(node*& head){
    int count = 0;
    while (head != NULL){
        ++count;
        head = head->next;
    }
    return count;
}

void pushBack(node*& head, svien stu){
    node* newNode = makeNode(stu);
    if (head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// selection sort
void sortData(node*& head){
    for (node* i = head; i != nullptr; i = i->next){
        node* minNode = i;
        for (node* j = i->next; j != nullptr; j = j->next){
            if (minNode->data.gpa > j->data.gpa){ //    kiểm tra điểm gpa và sắp xếp theo thứ tự tăng dần
                minNode = j;
            }
            else if (minNode->data.gpa == j->data.gpa){
                if (minNode->data.name > j->data.name){
                    minNode = j;
                }
            }
        }
        svien temp = minNode->data;
        minNode->data = i->data;
        i->data = temp;
    }
}

int main(){
    node* head = nullptr;
    svien nhat("Nhat", 3.75);
    svien tan("Tan", 0.1);
    svien nhan("Nhan", 3.75);
    svien tuan("Tuan", 3.7);
    pushBack(head, nhat);
    pushBack(head, tan);
    pushBack(head, nhan);
    pushBack(head, tuan);
    printList(head);
    sortData(head);
    printList(head);
    return 0;
}