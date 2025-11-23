#include <stdio.h>
int main(){
	int a, b, c, max, min;
	
	printf("Input three intagers:");
	scanf("%d%d%d", &a,&b, &c);
	max = a;
	if(b > max)max =b;
	if(c > max)max =c;


	min = a;
	if(b < min)min =b;
	if(c < min)min =c;
	
	printf("max = %d,min = %d\n",max, min);
} 
