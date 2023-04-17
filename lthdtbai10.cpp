#include<iostream>
using namespace std;
struct mathang
{
    char tenmh[20];
    float dongia;
    int soluong;
    float tongtien;
};
void nhap(mathang mh[100], int n){
    for(int i=0; i<n; i++){
        cout<<"Nhap vao ten mat hang: ";
        fflush(stdin);
        fgets(mh[i].tenmh, sizeof(mh[i].tenmh),stdin);
        cout<<"Nhap so luong: ";cin>>mh[i].soluong;
        cout<<"Nhap don gia: ";cin>>mh[i].dongia;
        mh[i].tongtien=mh[i].soluong*mh[i].dongia;
    }
}
void xuat(mathang mh[100], int n){
    cout<<"DANH SACH HANG HOA LA: \n";
    for(int i=0; i<n; i++){
        cout<<mh[i].tenmh<<endl<<mh[i].soluong<<endl<<mh[i].dongia<<endl<<mh[i].tongtien<<endl;
    }
}
float tong(mathang mh[100], int n){
    float sum=0;
    for(int i=0; i<n; i++){
        sum+=mh[i].tongtien;
    }
    return sum;
}
int main(){
    mathang mh[100];
    int n;
    cout<<"Nhap vao so luong mat hang; ";
    cin>>n;
    nhap(mh,n);
    xuat(mh,n);
    float tongtien=tong(mh,n);
    cout<<"Tong tien cua n mat hang la: "<<tongtien<<endl;
    return 0;
}