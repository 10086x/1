#include<iostream>
#include<cstdio>
using namespace std;
typedef struct front
{
    int* data;
    int length;
    int *top;
}xulie;
void init(xulie &L)
{
    L.data=new int[100];
    L.length=0;
    L.top=L.data;
}


void input(xulie &L,int x)
{
    L.data[L.length++]=x;
    L.top++;
}
void output(xulie &L)
{
    printf("%d",L.data[L.length-1]);
    printf("\n");
    L.length--;
    L.top--;
}
int delect(xulie &L)
{
    if(L.top == L.data){
        printf("队列为空");
        return 0;
    }
    return 1;
}
int get(xulie &L)
{
    return *(L.top - 1);
}
int select(xulie &L,xulie &want)
{
    xulie p;
    init(p);
    int i=0;
    int j=0;
    while(i < L.length && j < want.length){
        if(L.data[i] == want.data[j]){
            printf("找到%d\n",L.data[i]);
            i++;
            j++;
        }else if(get(L) == want.data[j]){
            output(L);
            j++;
        }else{
            input(p,L.data[i]);
            i++;
        }
    }
    
    if(j == want.length){
        return 1;
    }else{
        printf("不可");
        return -1;
    }
}
int main()
{
    xulie L;
    init(L);


    while(1){
        int number;
        if(scanf("%d",&number) != 9999){
            break;
        }
        input(L,number);
    }
    
    xulie want;
    init(want);
    while(1){
        int number;
        if(scanf("%d",&number) != 9999){
            break;
        }
        input(want,number);
    }
    
    if(select(L,want) == -1){
        printf("不可");
    }else{
        printf("可");
    }
    
    return 0;
}
