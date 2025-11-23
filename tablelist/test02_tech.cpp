#include<iostream>
#define NUM 26
using namespace std;
typedef struct Node{
    char data;
    Node* next;
}LNode, *LinkList;
void initlist(LinkList &L){
    LinkList q, r;
    L->data='A';
    L->next=L;
    char s[]="BCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0;i<NUM;i++){
        Node* p=new LNode;
        p->data=s[i];
        q->next=r;
        p->next=L;
        q=r;
    }

};
void printlist(LinkList L,int pos){
    LNode *p=L;
    for (int i=0;i<pos;i++){
        p=p->next;
    }
    for (int i=0;i<NUM;i++){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}