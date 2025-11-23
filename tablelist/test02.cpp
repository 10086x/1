#include<iostream>
using namespace std;
struct Node{
    char data;
    Node* next;
};

void initlist(Node* &L){
    Node* q;
    L->data='A';
    L->next=L;
    q=L;
    char s[]="BCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i=0;i<26;i++){
        Node* p=new Node;
        p->data=s[i];
        q=p;
        L->next=q;
        p->next=L;
    }
};
Node* find(Node* L,int x){
    Node* p=L;
    switch(x>0?1:-1){
        case 1:
            for(int i=0;i<x;i++){
                p=p->next;
            }
            break;
        case -1:
            while(p->next!=NULL){
                p=p->next;
            }
            break;
    }
    return p;
}
int output(Node* p){
    for (int i=0;i<26;i++){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
int main(){
    Node* L;
    initlist(L);
    int x= 12;
    Node* q=find(L,x);
    output(q);
    return 0;
}
