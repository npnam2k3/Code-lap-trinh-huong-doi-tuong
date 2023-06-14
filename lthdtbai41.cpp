// Thời điểm là một loại ngày tháng và cũng là một loại thời gian
// nhưng có thêm địa điểm. Ngày tháng có ngày, tháng, năm. Thời gian có giờ và phút. Nhập vào một thời điểm,
// đưa ra địa điểm, ngày và thời gian của thời điểm đó ở dạng Địa điểm, ngày dd/mm/yy - h:mm.
// Ví dụ: Hà Nội, ngày 22/04/19 - 9:30.
#include<iostream>
#include<stdio.h>
using namespace std;
class NgayThang
{
    private:
        char ngay[5],thang[5],nam[5];
    public:
        void nhap();
        void hien();      
};

class ThoiGian
{
    private:
        char gio[3], phut[3];
    public:
        void nhap();
        void hien();
};

class ThoiDiem:public NgayThang,public ThoiGian
{
    private:
        char diaDiem[50];
    public:
        void nhap();
        void hien();
};
//===chuong trinh chinh===
int main()
{
    ThoiDiem td;

    cout<<"Nhap vao thoi diem: ";
    td.nhap();
    cout<<"\nThoi diem vua nhap la: \n";
    td.hien();

    cout<<endl;
    return 0;
}
//dimh nghia ham
void NgayThang::nhap()
{
    cout<<"\nNhap ngay: ";
    cin>>ngay;
    cout<<"\nNhap vao thang: ";
    cin>>thang;
    cout<<"\nNhap vao nam: ";
    cin>>nam;
}

void NgayThang::hien()
{
    cout<<"ngay "<<ngay<<"/"<<thang<<"/"<<nam;
}

void ThoiGian::nhap()
{
    cout<<"\nNhap vao gio: ";cin>>gio;
    cout<<"\nNhap vao phut: ";cin>>phut;
}

void ThoiGian::hien()
{
    cout<<gio<<":"<<phut;
}

void ThoiDiem::nhap()
{
    cout<<"\nNhap dia diem: ";
    scanf(" ");
    cin.get(diaDiem,sizeof(diaDiem));
    NgayThang::nhap();
    ThoiGian::nhap();
}

void ThoiDiem::hien()
{
    cout<<diaDiem<<" ,";
    NgayThang::hien();
    cout<<" - ";
    ThoiGian::hien();
}