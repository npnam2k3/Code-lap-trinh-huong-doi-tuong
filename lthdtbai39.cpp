/* Một nhân sự luôn có họ tên và ngày sinh.
Sinh viên là một loại nhân sự có thêm mã sinh viên và điểm tbc.
Nhập vào thông tin của một sinh viên. Đưa ra màn hình các thông tin về sinh viên có kèm theo
đánh gia, nếu điểm TBC >=8.0 thì đánh giá là sinh viên giỏi.*/
#include<iostream>
#include<stdio.h>

using namespace std;
//khai bao lop
class NhanSu
{
    private:
        char hoten[100];
        char ngaysinh[11];
    public:
        void nhap();
        void hien();
};

class SinhVien : public NhanSu
{
    private:
        char maSV[10];
        float diemTB;
    public:
        void nhap();
        void hien();
};

//chuong trinh chinh
int main()
{
    SinhVien s;
    cout<<"Nhap vao thong tin sinh vien: \n";
    s.nhap();
    cout<<"\n\nThong tin sinh vien vua nhap la: \n";
    s.hien();
    cout<<endl;
    return 0;
}

//dinh nghia ham
void NhanSu::nhap()
{
    cout<<"Nhap ho ten: ";
    scanf(" "); cin.get(hoten, sizeof(hoten));
    cout<<"Nhap ngay sinh (dd/mm/yyyy): ";
    cin>>ngaysinh;
}

void NhanSu::hien()
{
    cout<<"Ho ten: "<<hoten;
    cout<<"\nNgay sinh: "<<ngaysinh;
}

void SinhVien::nhap()
{
    NhanSu::nhap();
    cout<<"Nhap ma sinh vien: ";cin>>maSV;
    cout<<"Nhap diem tbc: ";cin>>diemTB;
}

void SinhVien::hien()
{
    NhanSu::hien();
    cout<<"\nMa sinh vien: "<<maSV;
    cout<<"\nDiem trung binh cong: "<<diemTB;
    if(diemTB>=8.0)
        cout<<"\nSinh vien gioi\n";
}