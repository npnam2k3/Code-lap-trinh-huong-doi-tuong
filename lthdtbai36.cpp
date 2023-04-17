/*Tính tổng n số phức. Yêu cầu dùng toán tử + để cộng hai số phức,
dùng toán tử nhập >> nhập vào số phức, dùng toán tử xuất << để đưa ra số phức ở dạng a + bi,
có thể khởi tạo giá trị ban đầu cho phần thực và phần ảo.*/
#include<iostream>
#include<stdio.h>
using namespace std;
//khai bao lop
class SoPhuc
{
    private:
        int a,b;
    public:
        SoPhuc();
        friend istream& operator>>(istream &cin, SoPhuc &p);
        friend ostream& operator<<(ostream &cout, SoPhuc &p);
        SoPhuc operator+(SoPhuc &p);
};

//chuong trinh chinh
int main()
{
    SoPhuc a[100], tong;
    int n;
    cout<<"Nhap so luong so phuc: ";cin>>n;
    cout<<"\nNhap vao so phuc: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\nNhap so phuc thu "<<i+1<<endl;
        cin>>a[i];
    }

    cout<<"\nCac so phuc vua nhap la: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\nSo phuc "<<i+1<<": ";
        cout<<a[i];
    }
    for(int i=0; i<n; i++)
    {
        tong = tong + a[i];
    }
    cout<<"\nTong cac so phuc la: "<<tong;
    cout<<endl;
    return 0;
}

//dinh nghia ham
SoPhuc::SoPhuc():a(0),b(0)
{

}

istream& operator>>(istream &cin, SoPhuc &p)
{
    cout<<"Nhap phan thuc: ";cin>>p.a;
    cout<<"Nhap phan ao: "; cin>>p.b;
    return cin;
}

ostream& operator<<(ostream &cout, SoPhuc &p)
{
    if(p.b<0)
    {
        cout<<p.a<<"-"<<-p.b<<"i";
    }
    else cout<<p.a<<"+"<<p.b<<"i";
    return cout;
}

SoPhuc SoPhuc::operator+(SoPhuc &p)
{
    SoPhuc tong;
    tong.a = a+p.a;
    tong.b = b+p.b;
    return tong;
}