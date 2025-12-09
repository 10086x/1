#include <iostream>
#include <cstring>
using namespace std;
class person{
    private:
        int name;
        int born;
        char sex[10];    
        int point;
    public:
        person(int name,int born,char sex[10],int point){
            this->name=name;
            this->born=born;
            strcpy(this->sex,sex);
            this->point=point;
        }
        ~person(){
            cout<<"delete:name:"<<name<<endl;
            cout<<"delete:born:"<<born<<endl;
            cout<<"delete:sex:"<<sex<<endl;
            cout<<"delete:point:"<<point<<endl;
            delete[] sex;
        
        }
        void printperson(){
            cout<<"name:"<<name<<endl;
            cout<<"born:"<<born<<endl;
            cout<<"sex:"<<sex<<endl;
            cout<<"point:"<<point<<endl;

        }
};
class student:public person{
    private:
        int id;
        int score;
    public:
        student(int name,int born,char sex[10],int point,int id):person(name,born,sex,point){
            this->id=id;
        }
        ~student(){
            cout<<"delete:id:"<<id<<endl;
        }
        void printstudent(){
            printperson();
            cout<<"id:"<<id<<endl;
        }
};
class teacher:public person{
    private:
        char projectname[10];
    public:
        teacher(int name,int born,char sex[10],int point,char projectname[10]):person(name,born,sex,point){
            strcpy(this->projectname,projectname);
        }
        ~teacher(){
            cout<<"delete:projectname:"<<projectname<<endl;
            delete[] projectname;
        }
        void printteacher(){
            printperson();
            cout<<"projectname:"<<projectname<<endl;
        }
};
int main(){
    person p(1,2000,"male",90);
    p.printperson();
    student s(1,2000,"male",90,1001);
    s.printstudent();
    teacher t(1,2000,"male",90,"project1");
    t.printteacher();
    return 0;
}