#include<stdio.h>
#include<string.h>
void List(char *str1,char *str2){
    int a=strlen(str1);
    int b =strlen(str2);

    int n=0;
    for (int i=0; i<=a; i++){
        int m =0;
        for (int j=0; j<=b; j++){
            if (str1[i]==str2[j]){
                m=1;
                break;
            }
        }
        if (!m){
            str1[n]=str1[i];
            n++;
        }
    }
    str1[n]='/0';
}
int main(){
    char str1[70], str2[70];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    List(str1, str2);
}
