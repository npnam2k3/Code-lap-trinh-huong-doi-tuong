#include<iostream>
using namespace std;
class PhanSo
{
    private:
        int tuso, mauso;
    public:
        void nhap();
        void xuat();
        PhanSo operator+(PhanSo &p);
        PhanSo operator-(PhanSo &p);
        PhanSo operator*(PhanSo &p);
        PhanSo operator/(PhanSo &p);
};

int main()
{
    PhanSo p1,p2,tong,hieu,tich,thuong;
    cout<<"Nhap vao phan so thu 1: "<<endl;
    p1.nhap();
    cout<<"Phan so 1 la: ";
    p1.xuat();

    cout<<"\nNhap vao phan so thu 2: "<<endl;
    p2.nhap();
    cout<<"Phan so 2 la: ";
    p2.xuat();

    tong = p1+p2;

    hieu=p1-p2;
    tich = p1*p2;
    thuong = p1/p2;
    cout<<"\nTong hai phan so la: "; tong.xuat();
    cout<<"\nHieu hai phan so la: "; hieu.xuat();
    cout<<"\nTich hai phan so la: ";tich.xuat();
    cout<<"\nThuong hai phan so la: "; thuong.xuat();
    cout<<endl;
    return 0;
}

void PhanSo::nhap()
{
    cout<<"Nhap vao tu so: ";cin>>tuso;
    cout<<"Nhap vao mau so: ";cin>>mauso;
}

void PhanSo::xuat()
{
    cout<<tuso<<"/"<<mauso;
}

PhanSo PhanSo::operator+( PhanSo &p)
{
    PhanSo tong;
    tong.tuso = this->tuso * p.mauso + p.tuso*this->mauso;
    tong.mauso=this->mauso * p.mauso;
    return tong;
}

PhanSo PhanSo::operator-(PhanSo &p)
{
    PhanSo hieu;
    hieu.tuso= this->tuso * p.mauso - p.tuso*this->mauso;
    hieu.mauso=this->mauso * p.mauso;
    return hieu;
}
PhanSo PhanSo::operator*(PhanSo &p)
{
    PhanSo tich;
    tich.tuso = this->tuso*p.tuso;
    tich.mauso = this->mauso*p.mauso;
    return tich;
}
PhanSo PhanSo::operator /(PhanSo &a)
{
    PhanSo thuong;
    thuong.tuso = this->tuso * a.mauso;
    thuong.mauso = this->mauso * a.tuso;
    return thuong;
}