#include<iostream>
#include<fstream>
using namespace std;
//===Khai bao lop
class Matran
{
    private:
        enum{size = 30};
        int a[size][size];
        int m, n;
    public:
        Matran();
        Matran operator+(Matran &b);

        //ham ban
        friend ifstream& operator>>(ifstream &fin, Matran &mt);
        friend ostream& operator<<(ostream &cout, Matran &mt);
};
int main()
{
    Matran A,B,C;
    ifstream finA("matran-A.txt");
    finA>>A;
    cout<<"Ma tran A doc tu tep la: \n";
    cout<<A;

    ifstream finB("matran-B.txt");
    finB>>B;
    cout<<"Ma tran B doc tu tep la: \n";
    cout<<B;
    C=A+B;
    cout<<"Ma tran tong la: \n"<<C;
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
Matran::Matran():m(0),n(0){}
Matran Matran::operator+(Matran &b)
{
    Matran tg;
    if(m!= b.m || n!=b.n){
        cout<<"2 ma tran phai cung kich thuoc!";
        return tg;
    }
    tg.m = m;tg.n=n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            tg.a[i][j] = a[i][j] + b.a[i][j];
        }
    }
    return tg;
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
ostream& operator<<(ostream& cout, Matran &mt)
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