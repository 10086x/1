#include<iostream>
using namespace std;
struct node
{
    int data;
    node* lnext;
    node* rnext;
};

void check(int *a, int *b, int n){
    int *space=new int[10];
    for(int i=0;i<=10;i++){
        space[i]=0;
    }
    int *m=space;
    int d=0;
    for(int i=0;a[i]!=0;i++){
        if(a[i]==b[d]){
            d++;
        }else if(*m==b[d]){
            m--;
            d++;
        }
        else{
            *m=b[d];
            m++;
            d++;
        }

    }
    if(m==space){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
void CreateList1(node* &head, int* &data, int &index, int size){
    if(index >= size || data[index] == 0){ 
        head = NULL;
        return;
    }
    
    head = new node;
    head->data = data[index];
    CreateList1(head->lnext, data, ++index, size);  
    CreateList1(head->rnext, data, ++index, size);  
}
void CreateList2(node* &head, int* &data, int &index, int size){
    if(index >= size || data[index] == 0){ 
        head = NULL;
        return;
    }
    
    head = new node;
    head->data = data[index];
    CreateList2(head->lnext, data, ++index, size);  
    CreateList2(head->rnext, data, ++index, size);  
}
//前序遍历
void PreOrder(node* head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    PreOrder(head->lnext);
    PreOrder(head->rnext);
     cout<<endl;
}
//中序遍历
void InOrder(node* head){
    if(head==NULL){
        return;
    }
    InOrder(head->lnext);
    cout<<head->data<<" ";
    InOrder(head->rnext);
     cout<<endl;
}
//后序遍历
void PostOrder(node* head){
    if(head==NULL){
        return;
    }
    PostOrder(head->lnext);
    PostOrder(head->rnext);
    cout<<head->data<<" ";
     cout<<endl;
}
//二分查找法
int BinarySearch(int* a, int n, int key){
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(key<a[mid]){
            high=mid-1;
        }
        else if(key>a[mid]){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int binary(int* a, int n, int key){
    int tap=n/2;

    while(true){
        if(key<a[tap]){
            tap=tap/2;
        }
        else if(key>a[tap]){
            tap=tap+tap/2;
        }
        else{
            return tap;
        }
        if(tap==0||tap==n){
            return -1;
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return 0;
}