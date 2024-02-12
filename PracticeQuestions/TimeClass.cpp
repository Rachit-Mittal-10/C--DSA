#include<iostream>
#include<string.h>
using namespace std;

// Addition of Time

class Time{
    int hour;
    int minute;
    int seconds;
    
    public:
        void GetTime(void){
            string time_;
            cout << "Time in HH:MM:SS format";
            cin >> time_;
            hour = stoi(time_.substr(0,2));
            minute = stoi(time_.substr(3,2));
            seconds = stoi(time_.substr(6,2));
        }
        Time Time_Addition(Time A,Time B){
            Time Answer;
            Answer.seconds =(A.seconds + B.seconds)%60;
            Answer.minute = (A.minute + B.minute)%60 + (A.seconds + B.seconds)/60;
            Answer.hour = (A.hour + B.hour) + (A.minute + B.minute)/60;
            
            if(Answer.minute == 60){
                Answer.hour++;
                Answer.minute = 0;
            }
            return Answer;
        }
        
        void PrintObject(){
            cout << hour << ":" << minute << ":" << seconds << endl;
        }
};

int main(void){
    Time a;
    Time b;
    Time c;
    a.GetTime();
    b.GetTime();
    c = c.Time_Addition(a,b);
    c.PrintObject();
    return 0;
}