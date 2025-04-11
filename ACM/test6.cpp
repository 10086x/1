#include<stdio.h>
#include<string.h> 
int main(){
	int now =0; 
	int sum = 0;  // 每次循环重置求和变量
	int last = 0; // 在循环外声明计数器
	int need[100]; 
	for (int i = 0; i<=1000;i++){
		char h[1000]; 
		sprintf(h, "%d" , i); 
		now =strlen(h);
		
		int num[now] ;
		for ( int b , e= 0 , d =i ; b <=now; b++ ,d/=10){
			e =d%10;
			num[b] =e;
			sum +=num[b]*num[b]*num[b];	
		}
		if (i == sum){
			last++;
			need[last] = i;
		}
		
		
	}	 
	for (int g =0 ; g <=last ;g++){
		printf("%d",need[g]);
	}
} 
