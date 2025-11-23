#include <stdio.h>

int main()
{
  int x, b0, b1, b2;         //定义变量

  printf("please input an integer x: ");  //提示用户输入一个整数
  scanf("%d", &x);           //输入一个整数

  b2 = x / 100;              //获取百位数
  b1 = (x - b2 * 100) / 10;  //获取十位数
  b0 = x % 10;               //获取个位数

  printf("bit2 = %d, bit1 = %d, bit0 = %d\n", b2, b1, b0);  //输出结果
  return 0;
}
