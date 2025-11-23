#include <stdio.h>

int main()
{
  int x, b0, b1, b2;         //瀹氫箟鍙橀噺

  printf("please input an integer x: ");  //鎻愮ず鐢ㄦ埛杈撳叆涓€涓暣鏁?
  scanf("%d", &x);           //杈撳叆涓€涓暣鏁?

  b2 = x / 100;              //鑾峰彇鐧句綅鏁?
  b1 = (x - b2 * 100) / 10;  //鑾峰彇鍗佷綅鏁?
  b0 = x % 10;               //鑾峰彇涓綅鏁?

  printf("bit2 = %d, bit1 = %d, bit0 = %d\n", b2, b1, b0);  //杈撳嚭缁撴灉
  return 0;
}
