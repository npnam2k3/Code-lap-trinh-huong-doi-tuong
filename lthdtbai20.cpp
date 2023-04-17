/*Cho ma trận nguyên Amxn. Tính tổng và trung bình cộng
các phần tử của ma trận. Đưa ra ma trận chuyển vị của A. Ma trận Amxn đọc từ tệp văn bản "matran.txt".*/
#include<iostream>
#include<fstream>
using namespace std;
//===Khai bao lop===
class Matran
{
    private:
        enum{size=30};
        int a[size][size];
        int m,n;
    public:
        Matran();
        Matran(int x, int y);
        friend ifstream& operator>>(ifstream &fin, Matran &mt);
        friend ostream& operator<<(ostream &cout, Matran &mt);
        int Tong();
        float TBC();
        void ChuyenVi();
};
int main()
{
    Matran a;
    ifstream fin("matran-A.txt");
    fin>>a;
    cout<<"Ma tran vua doc tu tep la: "<<endl;
    cout<<a;
    cout<<"Ma tran chuyen vi la: \n";
    a.ChuyenVi();
    int sum=a.Tong();
    float tbc=a.TBC();
    cout<<"Tong ma tran la: "<<sum;
    cout<<"\nTrung binh cong la: "<<tbc;
    cout<<endl;
    return 0;
}
Matran::Matran():m(5),n(5){}
Matran::Matran(int x, int y)
{
    if(x>size || y>size)
    {
        cout<<"Ma tran phai co so hang va so cot <= "<<size;
        cout<<"\nDua ve mac dinh: ";
        m=5;n=5;
    }else{
        m=x;n=y;
    }
}
ifstream& operator>>(ifstream &fin, Matran &mt)
{
    fin>>mt.m>>mt.n;
    for(int i=0; i<mt.m; i++)
    {
        for(int j=0; j<mt.n; j++)
        {
            fin>>mt.a[i][j];
        }
    }
    return fin;
}
ostream& operator<<(ostream &cout, Matran &mt)
{
    for(int i=0; i<mt.m; i++)
    {
        for(int j=0; j<mt.n; j++)
        {
            cout<<mt.a[i][j]<<" ";
        }
        cout<<endl;
    }
    return cout;
}
int Matran::Tong()
{
    int sum=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=a[i][j];
        }
    }
    return sum;
}
float Matran::TBC()
{
    return (float)Tong()/(m*n);
}
void Matran::ChuyenVi()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}