#include<iostream>
using namespace std;
typedef struct node{
	int length;
	node *lfirst=NULL;
	node *rfirst=NULL;
	int date=0;
	node *lnode=NULL;
	node *rnode=NULL;
	
}ad, *poad;
void buildhshu(int a,node *sd){
	if(sd==NULL){
		sd=new node;
		sd->length=1;
		sd->date=1;
		buildhshu(a,sd);
	}else if(sd!=NULL&&sd->length !=a){
		node *il=new node;
		node *ir=new node;
		sd->lnode =il;
		sd->rnode =ir;
		il->lfirst =sd->lfirst->rnode ;
		ir->rfirst =sd->rfirst->lnode ;
		il->date=sd->date+sd->lfirst->rnode->date;
		ir->date=sd->date+sd->rfirst->lnode->date;
		il->rfirst =sd;
		ir->lfirst =sd;
		il->length =sd->length +1;
		ir->length =sd->length +1;
		buildhshu(a,ir);
		buildhshu(a,il);
	}
}
int main(){
	node *i;
	int a=9;
	buildhshu(a,i);
	int e;
	node *m;
	while(a==0){
		a--;
		m=i->lfirst;
	}
	e=m->date;
	printf("%d",e);
}
