#include <stdio.h>
	
int main()
{
  unsigned long no;               //瀛﹀彿
  unsigned int year, month, day;  //鐢熸棩锛氬勾銆佹湀銆佹棩
  unsigned char sex;              //鎬у埆
  float chinese, math, english;   //璇枃銆佹暟瀛︺€佽嫳璇垚缁?
  float total, average;           //鎬诲垎銆佸钩鍧囧垎
	
  printf("input the student's NO: ");
  scanf("%8ld", &no);
  printf("input the student's Birthday(yyyy-mm-dd): ");
  scanf("%4d-%2d-%2d", &year, &month, &day);
  fflush(stdin);                 //娓呯┖杈撳叆缂撳啿鍖?
  printf("input the student's Sex(M/F): ");
  scanf("%c", &sex);
  printf("input the student's Scores(chinese, math, english): ");
  scanf("%f,%f,%f", &chinese, &math, &english);
  total = chinese + math + english;   //璁＄畻鎬诲垎
  average = total / 3;                //璁＄畻骞冲潎鍒?

  printf("\n===NO=======birthday==sex==chinese==math==english==total==average\n");
  printf("%08ld   %4d-%02d-%02d  %c     %-5.1f  %-5.1f  %-5.1f   %-5.1f   %-5.1f\n", 
	      no, year, month, day, sex, chinese, math, english, total, average);
  return 0;
}
