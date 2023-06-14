/** Viết chương trình quản lý nhân sự của một trường học;
nhân sự gồm có giảng viên và sinh viên; giảng viên có mã gv, họ tên và số bài báo;
sinh viên có mã sv, họ tên và điểm tbc. Nhập vào một số nhân sự trong đó có cả giảng viên
và sinh viên. Đưa ra thông tin của các nhân sự đã nhập kèm theo đánh giá:
giảng viên đánh giá là giỏi nếu số bài báo >=5, sinh viên đánh giá là giỏi
nếu điểm TBC>=8.0. Y/c cài đặt đa hình động.*/
#include<iostream>
#include<stdio.h>

using namespace std;
//Khai bao lop
class nhanSu
{
    private:
        char ten[100];
    public:
        virtual void nhap();
        virtual void Hien();
};

class giangVien:public nhanSu
{
    private:
        char maGV[10];
        int soBaiBao;
    public:
        void nhap();
        void Hien();
};

class sinhVien:public nhanSu
{
    private:
        char maSV[10];
        float diemTBC;
    public:
        void nhap();
        void Hien();
};

//Khai bao ham thong thuong
nhanSu* Nhap();
void HienNS(nhanSu *ns);

//===Chuong trinh chinh===
int main()
{
    nhanSu *ns[100];
    char traLoi;
    int n=0;
    
    do{
        ns[n++]=Nhap();
        cout<<"Co muon nhap tiep khong(c/k): "; 
        cin>>traLoi;
    }while(traLoi=='c' || traLoi=='C');

    cout<<"\nThong tin nhan su la: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\n\nNhan su thu "<<i+1<<" la:";
        HienNS(ns[i]);
    }
    cout<<endl;
    return 0;
}

//Dinh nghia ham
void nhanSu::nhap()
{
    cout<<"Nhap ten: ";
    scanf(" ");
    cin.getline(ten,sizeof(ten));
}

void nhanSu::Hien()
{
    cout<<"\nHo ten: "<<ten;
}

void giangVien::nhap()
{
    nhanSu::nhap();
    cout<<"\nNhap ma giang vien: ";
    cin>>maGV;
    cout<<"\nNhap so bai bao: ";
    cin>>soBaiBao;
}

void giangVien::Hien()
{
    nhanSu::Hien();
    cout<<"\nMa giang vien: "<<maGV;
    cout<<"\nSo bai bao: "<<soBaiBao;
    if(soBaiBao>=5)
        cout<<"\nGiang vien loai gioi";
}

void sinhVien::nhap()
{
    nhanSu::nhap();
    cout<<"\nNhap ma sinh vien: ";
    cin>>maSV;
    cout<<"\nNhap diem TBC: ";
    cin>>diemTBC;
}

void sinhVien::Hien()
{
    nhanSu::Hien();
    cout<<"\nMa sinh vien: "<<maSV;
    cout<<"\nDiem TBC: "<<diemTBC;
    if(diemTBC>=8.0)
        cout<<"\nSinh vien loai gioi";
}

//Dinh nghia ham thong thuong
nhanSu* Nhap()
{
    nhanSu *ns;
    char chon;
    cout<<"\nNhap vao lua chon (1-GV, 2-SV): \n";
    cin>>chon;
    switch(chon)
    {
        case '1':
            ns = new giangVien;
            break;
        case '2':
            ns = new sinhVien;
            break;
        default:
            ns = new giangVien; 
    }

    //dung da hinh dong de nhap
    ns->nhap();
    return ns;
}

void HienNS(nhanSu *ns)
{
    ns->Hien();
}