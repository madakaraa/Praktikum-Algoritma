#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
}; 

Node *top = nullptr;
Node *bot = nullptr;

Node* buatNode(int IB){ 
    Node *newNode = new Node;
    newNode->info = IB;
    newNode->next = nullptr;
    return newNode;
}

void push(int IB){
    Node *newNode = buatNode(IB);
    
    if(top == nullptr){
        top = bot = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void tampil(){
    Node *bantu = top;

    if(top == nullptr){
        cout << "Stack kosong";
    } else {
        while(bantu != nullptr){
            cout << bantu->info << " ";
            bantu = bantu->next;
        }
    }

    cout << endl;
}

void pop(){
    if(top == nullptr){
        cout << "Stack masih kosong" << endl;
    } else {
        Node *hapus = top;
        top = top->next;

        delete hapus;

        if(top == nullptr){
            bot = nullptr;
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    cout << "Isi stack: ";
    tampil();

    pop();

    cout << "Setelah pop: ";
    tampil();

    return 0;
}
