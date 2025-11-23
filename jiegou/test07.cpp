#include<iostream>
using namespace std;
class string {
    private:
        char *str;
    public:
        string(const char *s){
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
        ~string(){
            delete[] str;
        }
        void print(){
            cout<<str<<endl;
        }    
};

