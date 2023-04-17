/*Tính tích 2 ma trận nguyên: Cmxn = Amxp * Bpxn. Ma trận Amxp để trong
tệp văn bản "matran-A.txt", ma trận Bpxn để trong tệp văn bản "matran-B.txt". 
Đưa các ma trận ra màn hình theo định dạng hàng, cột.*/

#include<iostream>
#include<fstream>
using namespace std;

class Matran
{
    private:
        enum{size=30};
        int a[size][size];
        int m,n;
    public:
        Matran();
        int getM();
        int getN();
        Matran operator*(Matran &b);

        //ham ban
        friend ifstream& operator>>(ifstream &fin, Matran &b);
        friend ostream& operator<<(ostream &cout, Matran &b);
};
int main()
{
    Matran A,B,C;
    //doc ma tran tu tep
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");
    finA>>A;
    finB>>B;

    //in ra 2 ma tran
    cout<<"Ma tran A: \n";
    cout<<A;
    cout<<"Ma tran B: \n";
    cout<<B;
    
    //nhan hai ma tran
    if(A.getN() != B.getM()){
        cout<<"Hai ma tran khong nhan duoc!";
    }else{
        C=A*B;
        cout<<"Ma tran A * B = \n"<<C;
    }
    cout<<endl;
    return 0;
}
Matran::Matran():m(0),n(0){}
Matran Matran::operator*(Matran &b)
{
    Matran tich;
    // if(n != b.m)
    // {
    //     cout<<"Khong nhan duoc!";
    //     return tich;
    // }
    tich.m = m; tich.n = b.n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<b.n; j++)
        {
            tich.a[i][j] = 0;
            for(int k=0; k<n; k++)
            {
                tich.a[i][j] += a[i][k] * b.a[k][j];
            }
        }
    }
    return tich;
}
ifstream& operator>>(ifstream& fin, Matran &b)
{
    fin>>b.m>>b.n;
    for(int i=0; i< b.m; i++)
    {
        for(int j=0; j<b.n; j++)
        {
            fin>>b.a[i][j];
        }
    }
    return fin;
}
ostream& operator<<(ostream &cout, Matran &b)
{
    for(int i=0; i<b.m; i++)
    {
        for(int j=0; j<b.n; j++)
        {
            cout<<b.a[i][j]<<" ";
        }
        cout<<endl;
    }
    return cout;
}
int Matran::getM()
{
    return m;
}
int Matran::getN()
{
    return n;
}