/*Viết chương trình nhập vào n số phức. Đưa các số phức đã nhập ra màn hình.
Yêu cầu trong chương trình phải tạo đối tượng động.*/
#include<iostream>
using namespace std;

class Sophuc
{
    private:
        int a,b;
    public:
        void nhap();
        void hien();
};

int main()
{
    Sophuc *p;
    int n;
    cout<<"Nhap so luong so phuc: ";cin>>n;
    p=new Sophuc[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap so phuc thu: "<<i+1<<endl;
        p[i].nhap();
    }
    cout<<"Cac so phuc da nhap la: \n";
    for(int i=0; i<n; i++)
    {
        p[i].hien();
    }
    cout<<endl;
    return 0;
}
void Sophuc::nhap()
{
    cout<<"Nhap phan thuc: ";cin>>a;
    cout<<"Nhap phan ao: "; cin>>b;
}
void Sophuc::hien()
{
    if(b<0)
    {
        cout<<a<<"-"<<-b<<"i"<<endl;
    }else{
        cout<<a<<"+"<<b<<"i"<<endl;
    }
}