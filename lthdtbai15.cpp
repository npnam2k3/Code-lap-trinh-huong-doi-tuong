#include<iostream>
#include<math.h>
using namespace std;

class TamGiac
{
    private:
        float a,b,c;
    public:
        TamGiac(float a, float b, float c);
        void Nhap();
        void Xuat();
        float ChuVi();
        float DienTich();
};
int main()
{
    float a,b,c;
    TamGiac t(a,b,c);
    t.Nhap();
    t.Xuat();
    cout<<endl;
    return 0;
}
TamGiac::TamGiac(float a, float b, float c):a(a),b(b),c(c)
{

}

void TamGiac::Nhap()
{
    cout<<"Nhap vao 3 canh cua tam giac: ";
    cin>>a>>b>>c;
}

void TamGiac::Xuat()
{
    cout<<"Chu vi hinh tam giac la: "<<TamGiac::ChuVi();
    cout<<"\nDien tich tam giac la: "<<TamGiac::DienTich();
    cout<<endl;
}

float TamGiac::ChuVi()
{
    return a+b+c;
}

float TamGiac::DienTich()
{
    float p=(a+b+c)/2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}