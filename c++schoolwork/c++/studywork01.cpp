#include <iostream>
using namespace std;
typedef struct ListNode{
    char data;
    struct ListNode *start;
    struct ListNode *next;
}ListNode, *List;
void Initlist(List &p) {
    p = new ListNode;
    cout << "初始化中" << endl;
    p->data = 'A';
    ListNode *w;
    w = p;
    
    // 正确初始化变量并修复循环逻辑
    for (int Englishdata = 66; Englishdata <= 90; Englishdata++) {
        ListNode *q = new ListNode;
        q->data = char(Englishdata);
        w->next = q;
        q->start = w;
        w = q;
    }
    
    w->next = p;
    p->start = w;
}
void switchList(ListNode *p){
    char w=p->data;
    while(1){
        cout<<p->data;
        p=p->next;
        if(p->data==w){
            break;
        }
    }

}

void outputlist(ListNode *p,int input){
    if(input>=0){
        for(int i =input;i>0;i--){
            p=p->next;
        }
        switchList(p);

    }
    else if(input<0){
        for(int i =input;i<0;i++){
            p=p->start;
        }
        switchList(p);
    }
}
int checkput(int input){
    if(input>-26&&input<26){
        return 1;
    }
    return 0;
}

int main(){
    List p = NULL;
    Initlist(p);
    while(1){
        int input;
        cout<<endl<<"做出你的选择"<<endl;
        cin>>input;
        if(checkput(input)){
            outputlist(p,input);
        }
        else if(input==9999999){
            break;
        }
        else{
            cout<<"输入错误"<<endl;
        }

    }
    
}
