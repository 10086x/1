#include<stdio.h>
int main()
{
	unsigned short int a1, b1, c1, t;
	t=0;
	short int a,b,c;
    scanf("%hd%hd%hd",&a,&b,&c);
    a1=a;
    b1=b;
    c1=c;
    if (a1>b1){
    	t=a1;
    	a1=b1;
    	b1=t;    	
	}
    if (a1>c1){
    	t=a1;
    	a1=c1;
    	c1=t;    	
	}
    if (a1>b1){
    	t=a1;
    	a1=b1;	
    	b1=t;
	}
    if (b1>c1){
    	t=b1;
    	b1=c1;
    	c1=t; 
    	   	
	}
	a=a1;
	c=c1; 

    printf("%hu %hu %hd %hd",c1,a1,c,a);
    return 0;
}

