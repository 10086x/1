#include<iostream>
#include <cstring>
using namespace std;

class String {
private:
    char *str;
public:
    String(const char *s){
        int len=0;
        while(s[len]!='\0'){
            len++;
        }
        str=new char[len+1];
        for(int i=0;i<len;i++){
            str[i]=s[i];
        }
        str[len]='\0';
    }
    ~String(){
        delete[] str;
    }
    void print(){
        cout<<str<<endl;
    }
    void deleteword(char c){
        int len=strlen(str);
        int i=0;
        while(i<len){
            if(str[i]==c){
                for(int j=i;j<len-1;j++){
                    str[j]=str[j+1];
                }
                len--;
            }
            else{
                i++;
            }
        }
        str[len]='\0';
    } 
    void instendword(char c,char d){
        int len=strlen(str);
        for(int i=len-1;i>=0;i--){
            if(str[i]==c){
                str[i]=d;
            }
        }
    }
};

int main(){
    String s("hello world");
    s.print();
    s.deleteword('l');
    s.print();
    s.instendword('o','!');
    s.print();
    return 0;
}