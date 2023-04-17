#include<iostream>
#include<math.h>
using namespace std;

class Diem
{
    private:
        int x,y;
    public:
        void Nhap();
        void Xuat();
        float KhoangCach(Diem &b);
};
int main()
{
    Diem A,B;
    cout<<"Nhap tung do va hoanh do diem A: ";
    A.Nhap();
    cout<<"Nhap tung do va hoanh do diem B: ";
    B.Nhap();
    cout<<"Khoang cach giua 2 diem la: "<<A.KhoangCach(B);
    cout<<endl;
    return 0;
}
void Diem::Nhap()
{
    cout<<"Nhap x: ";cin>>x;
    cout<<"Nhap y: ";cin>>y;
}
void Diem::Xuat()
{
    cout<<"("<<x<<" , "<<y<<")"<<endl;
}
float Diem::KhoangCach(Diem &b)
{
    float c;
    c = sqrt((b.x-x)*(b.x - x) + (b.y - y) * (b.y - y));
    return c;
}