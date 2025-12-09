#include <iostream>
using namespace std;
void input(char *a)
{
    char *b=a;
    cout<<"请输入一个字符串：";
    while(1){
        cin>>b;
        if(*b=='\n')
        {
            break;
        }
        b++;
    }
}
void todo(char *a)
{
    char *b=a;
    b++;
    char *c=a;
    while(*b){
        c=b;
        b++;
        c++; 
    }
}
void select(char *a)
{
    char *b=a;
    while(*b){
        if(*b=='c')
        {
            todo(a);
        }
        b++;
    }
}
int main()
{
    char *a=new char[100];
    input(a);
    select(a);
    cout<<a;
    return 0;
}