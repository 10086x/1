#include<iostream>
#include <cstring>
using namespace std;
struct Node{
    char date=NULL;
    Node *left;
    Node *right;

};
class nodetree{

    private :
    Node *date;
    int size;
     void popdate(Node *x,char a){
        while(1){
            if(x->date==NULL){
                x->date=a;
                size++;
                return;
            }else if(x->date!=0&&x->left!=NULL){
                x=x->left;
                popdate(x,a);
            }
            else if(x->date!=0&&x->right!=NULL){
                x=x->right;
                popdate(x,a);
            }else if (x->right==NULL&&x->left!=NULL){
                return;
            }
        }
    }
    public:
     nodetree(){
        date = NULL;
        size = 0;
     }
     ~nodetree(){

        delete date;
     }
     void insert(Node *x, char a[]){
        for(int i=0;i<strlen(a);i++){
            popdate(x,a[i]);
        }
     }
     char showdate(Node *x){
        if(x->date!=NULL){
            return x->date;
        }
        else if(x->left!=NULL){
            return showdate(x->left);
        }
        else if(x->right!=NULL){
            return showdate(x->right);
        }
    }


};
int main(){
    nodetree nt;
    return 0;
}