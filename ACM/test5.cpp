#include<stdio.h>
int main(){
	int i, b, c ;
	b = 0;
	c = 0; 
	printf("请输入一个正整数：");
	scanf("%d",&i);

	for (int m = i;m != 0;m/=10){		
		if(m != 0){
			b++;
		}
	}
	int a[b] ;

	for (; i != 0;c++ , i/=10){		
		a[c] = i%10;	
	}
	for (int m = 0; m <b ;m++){
		printf("%d", a[m]);
		if (m==b-1)
		printf("\n");
	}
	for (int m = 0 ;m+1 < b ; m++){
		for (int d = 0 ;d+1 < b-m ; d++){
			if (a[d+1] < a[d]){
			c = a[d];
			a[d] = a[d+1];
			a[d+1] = c;
			}
		
		}
	} 
	printf("min:");
	for (int m = 0; m <b ;m++){
		printf("%d", a[m]);
		if(m == b-1)
		printf("\n");
	}
	printf("max:");
	for (int m = b-1; m >= 0 ;m--){
		printf("%d", a[m]);
	}
	return 0;	
} 
