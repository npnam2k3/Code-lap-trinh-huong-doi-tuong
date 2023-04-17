/* Nhập vào một danh sách n mặt hàng; mỗi mặt hàng có tên hàng, số lượng, đơn giá.
Tính tổng tiền của n mặt hàng.*/
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

class Mathang
{
    private:
        char tenMH[100];
        int soLuong;
        float donGia;
    public:
        void nhap();
        void xuat();
        float TinhTien();
};
int main()
{
    Mathang dsMH[100];
    float tongtien = 0;
    int n;
    cout<<"Nhap so luong mat hang: "; cin>>n;
    cout<<"Nhap danh sach mat hang: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\nNhap mat hang thu "<<i+1;
        cout<<endl;
        dsMH[i].nhap();
    }
    cout<<"\n\n\t\t\tDanh sach mat hang la: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"Mat hang thu "<<i+1<<endl;
        dsMH[i].xuat();
        cout<<"\n=========\n\n";
    }
    for(int i=0; i<n; i++)
        tongtien+=dsMH[i].TinhTien();
    cout<<"Tong so tien cua "<<n<<" mat hang la: "<<tongtien;
    cout<<endl;
    return 0;
}
void Mathang::nhap()
{
    cout<<"Nhap ten mat hang: ";
    cin.ignore();
    cin.get(tenMH,sizeof(tenMH));
    cout<<"Nhap so luong: "; cin>>soLuong;
    cout<<"Nhap don gia: "; cin>>donGia;
}
void Mathang::xuat()
{
    cout<<"Ten mat hang: "<<tenMH;
    cout<<"\nSo luong: "<<soLuong;
    cout<<"\nDon gia: "<<donGia;
    cout<<"\n=> Thanh tien: "<<Mathang::TinhTien();
}
float Mathang::TinhTien()
{
    return soLuong*donGia;
}