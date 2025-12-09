#include<iostream>
using namespace std;
int *outputlist(int a[],int *low, int *hugh){
    
    int *pointkey=&a[*low];
    int *pointkey2=&a[*low+1];
    while(*low<*hugh){
        if(a[*low]>*pointkey){
            int temp=a[*low];
            a[*low]=a[*hugh];
            a[*hugh]=temp;
            pointkey=low;
            low++;
        }
        else if(a[*low]<*pointkey){
            low++;
        }
        else if(a[*low]==*pointkey){
            int temp=a[*low];
            a[*low]=a[*pointkey2];
            a[*pointkey2]=temp;
            pointkey2++;
        }
        else if(a[*hugh]<*pointkey){
            int temp=a[*hugh];
            a[*hugh]=a[*low];
            a[*low]=temp;
            pointkey=hugh;
            hugh--;
        }
        else if(a[*hugh]==*pointkey){
            int temp=a[*hugh];
            a[*hugh]=a[*pointkey2];
            a[*pointkey2]=temp;
            pointkey2++;
        }   
        else if(a[*hugh]>*pointkey){
            hugh--;
        }

    }
    return pointkey;

}
int quicksort(int a[],int *low,int *hugh){
    int *pointkey=outputlist(a,low, hugh);

    while(*low<*hugh){
        int *pivotPos = outputlist(a, low, hugh);
        
        // 递归排序左子数组
        quicksort(a, low, pivotPos - 1);
        
        // 递归排序右子数组
        quicksort(a, pivotPos -1, hugh);
    }
}