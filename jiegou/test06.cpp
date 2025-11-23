#include <iostream>
using namespace std;    
class Clock{
    protected:
        int hour;
        int minute;
        int second;
    public:
        Clock(int hour,int minute,int second){
            this->hour=hour;
            this->minute=minute;
            this->second=second;
        }
        ~Clock(){
            cout<<"delete:hour:"<<hour<<endl;
            cout<<"delete:minute:"<<minute<<endl;
            cout<<"delete:second:"<<second<<endl;
        }
        void printclock(){
            cout<<"hour:"<<hour<<endl;
            cout<<"minute:"<<minute<<endl;
            cout<<"second:"<<second<<endl;
        }
};
class Date{
    protected:
        int year;
        int month;
        int day;
    public:
        Date(int year,int month,int day){
            this->year=year;
            this->month=month;
            this->day=day;
        }
        ~Date(){
            cout<<"delete:year:"<<year<<endl;
            cout<<"delete:month:"<<month<<endl;
            cout<<"delete:day:"<<day<<endl;
        }
        void printdate(){
            cout<<"year:"<<year<<endl;
            cout<<"month:"<<month<<endl;
            cout<<"day:"<<day<<endl;
        }
};
class ClockWithDate:public Clock,public Date{
    public:
        ClockWithDate(int hour,int minute,int second,int year,int month,int day):Clock(hour,minute,second),Date(year,month,day){
        }
        ~ClockWithDate(){
        }
        void printclockwithdate(){
            printclock();
            printdate();
        }
        void addscond(int s){
                this->second+=s;
            if(second>=60){
                this->minute+=this->second/60;
                this->second%=60;
            }
        };

};