#include<iostream>
using namespace std;

int UCLN(int a, int b);
class PhanSo{
    private:
        int tuso,mauso;
    public:
        void Nhap();
        void Xuat();
        PhanSo Tong(PhanSo &p);
        void RutGon();
};
//Khai bao ham
int main()
{
    PhanSo p1,p2,tong;
    p1.Nhap();
    p2.Nhap();
    cout<<"Phan so chua rut gon: ";
    cout<<"\nPhan so 1 = ";
    p1.Xuat();
    cout<<"Phan so 2 = ";
    p2.Xuat();
    tong=p1.Tong(p2);
    cout<<"p1 + p2 = ";tong.Xuat();

    cout<<"Phan so o dang rut gon: ";
    cout<<"\nPhan so 1 = ";p1.RutGon();p1.Xuat();
    cout<<"Phan so 2 = ";p2.RutGon(); p2.Xuat();
    cout<<"P1 + P2 = ";tong.RutGon();tong.Xuat();
    cout<<endl;
    return 0;
}
//dinh nghia ham
void PhanSo::Nhap()
{
    cout<<"Nhap tu so: ";cin>>tuso;
    cout<<"Nhap mau so: "; cin>>mauso;
}
void PhanSo::Xuat()
{
    cout<<tuso <<"/"<<mauso<<endl;
}
PhanSo PhanSo::Tong(PhanSo &p)
{
    PhanSo tong;
    tong.tuso = tuso * p.mauso + p.tuso * mauso;
    tong.mauso = mauso * p.mauso;
    return tong;
}
void PhanSo::RutGon()
{
    int uc = UCLN(tuso,mauso);
    tuso = tuso/uc;
    mauso = mauso/uc;
}
int UCLN(int a, int b)
{
    if(a%b==0){
        return b;
    }else{
        return UCLN(b,a%b);
    }
}