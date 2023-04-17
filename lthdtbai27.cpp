/*Viết chương trình nhập vào danh sách n sinh viên,
mỗi sinh viên có thông tin về mã sinh viên, tên và điểm tbc.
Mã SV là các số nguyên được lấy tự động có giá trị từ 11 trở đi.
Đưa ra màn hình số lượng (không dùng n) và danh sách sinh viên đã nhập.
Yêu cầu trong chương trình có sử dụng biến tĩnh và hàm tĩnh;
sử dụng mảng đối tượng động.*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class SinhVien
{
    private:
        int maSV;
        char ten[100];
        float diemTB;

        static int stt;
    public:
        void nhap();
        void hien();
        static int laySL();
};
int SinhVien::stt = 10;
int main()
{
    SinhVien *ds[100];
    char traloi;
    int n,i=0;
    do{
        //tao doi tuong sinh vien
        ds[i] =  new SinhVien;

        //Nhap thong tin sinh vien
        ds[i++]->nhap();

        //hoi co nhap tiep khong 
        cout<<"Co nhap tiep khong?(c/k)";
        cin>>traloi;

    }while(traloi == 'c' || traloi == 'C');
    n = SinhVien::laySL();
    system("cls");
    cout<<"\n\n\nSo luong sinh vien la: "<<n<<endl;
    cout<<"\t\t\tThong tin sinh vien da nhap la: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"\nSinh vien thu "<<i+1;
        ds[i]->hien();
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
void SinhVien::nhap()
{
    maSV = ++stt;
    cout<<"Nhap thong tin sinh vien co ma: "<<maSV;
    cout<<"\nNhap ten: ";scanf(" ");
    cin.getline(ten,sizeof(ten));
    cout<<"Nhap diem trung binh: ";cin>>diemTB;
}
void SinhVien::hien()
{
    cout<<"\nMa sinh vien: "<<maSV;
    cout<<"\nTen sinh vien: "<<ten;
    cout<<"\nDiem trung binh: "<<diemTB;
}
int SinhVien::laySL()
{
    return stt-10;
}