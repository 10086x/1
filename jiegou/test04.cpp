#include <iostream>
using namespace std;
struct Node{
    int deep;
    int data;
    Node *nextl=NULL;
    Node *nextr=NULL;
};

class bianli{
    private:
        Node *head;
        Node *tail;
        int length;
    public:
        bianli(Node *head=new Node,int length=1){
            this->head=head;
            head->deep=0;
            this->length=length;
        }
        ~bianli(){
            delete head;

        }
        void printmii(){
             Node *p=head;
             while(p!=NULL){
                 cout<<p->data<<endl;
                 p=p->nextl;
             }
        }
        void printiim(){
             Node *p=head;
             while(p!=NULL){
                 cout<<p->data<<endl;
                 p=p->nextr;
             }
        }

        void printiim1(Node *p){
            printiim();
            printmii();
            cout<<p->data;
        }

        void printmii1(Node *p){
            printmii();
            printiim();
            cout<<p->data;
        }
        void printimi1(Node *p){
            printmii();
            cout<<p->data;
            printiim();
        
        }
        void writenopde(Node *p){
             printf("=======let's write node left======\n");
             for(int i=0;;i++){
                Node *d=new Node;

                printf("input node data:");
                 int input_data;
                scanf("%d",&input_data);
                if(input_data==0){
                    break;
                }
                else{
                    d->data=input_data;
                    d->deep=p->deep+1;
                    d->nextr=p->nextr;
                    p->nextr=d;
                    writenopde(d);
                }
            }


             printf("=======let's write node right======\n");
             for(int i=0;;i++){
                Node *e=new Node;
                printf("input node data:");
                int input_data;
                scanf("%d",&input_data);
                if(input_data==0){
                    break;
                }
                else{
                    e->data=input_data;
                    e->deep=p->deep+1;
                    e->nextr=p->nextr;
                    writenopde(e);
                }
            }
        }
        void writenopde(){
            writenopde(head);
        }

};
int main(){
    bianli b;
    b.writenopde();
    return 0;
}
