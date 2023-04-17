#include<iostream>
using namespace std;
class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time(int h, int m);
        void display();
        void add_minutes(int m);
};
int main()
{
    int h,m,n;
    cout<<"Nhap vao gio va phut: ";cin>>h>>m;
    Time t(h,m);
    cout<<"Nhap vao thoi gian n: ";cin>>n;
    t.add_minutes(n);
    cout<<"Thoi gian sau n phut nhap la: ";
    t.display();
    cout<<endl;
    return 0;
}
//Dinh nghia ham
Time::Time(int h, int m):hours(h),minutes(m)
{

}

void Time::display()
{
    cout<<hours<<" : "<<minutes<<endl;
}

void Time::add_minutes(int m)
{
    minutes+=m;
    hours+=minutes/60;
    minutes%=60;
    hours%=24;
}