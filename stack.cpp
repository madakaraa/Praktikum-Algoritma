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
    while(bantu != nullptr){
        cout << bantu->info << " ";
        bantu = bantu->next;
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    
    tampil();
}
