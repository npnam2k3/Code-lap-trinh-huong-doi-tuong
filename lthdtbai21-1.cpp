#include<iostream>
#include<fstream>

using namespace std;
class matran
{
    private:
        int a[30][30];
        int hang, cot;
    public:
        matran();
        void DocMT(const char *tenTep);
        void Xuat();
        matran Tong(matran &mt);
};
int main()
{
    matran A,B,C;
    A.DocMT("matran-A.txt");
    B.DocMT("matran-B.txt");

    cout<<"Ma tran A: \n";
    A.Xuat();
    cout<<"\nMa tran B: \n";
    B.Xuat();
    C=A.Tong(B);
    cout<<"\nMa tran tong la: \n";
    C.Xuat();
    cout<<endl;
    return 0;
}

matran::matran():hang(0),cot(0)
{

}

void matran::DocMT(const char *tenTep)
{
    ifstream fin(tenTep);
    fin>>hang>>cot;
    for(int i=0; i<hang; i++)
    {
        for(int j=0; j<cot; j++)
        {
            fin>>a[i][j];
        }
    }
}
void matran::Xuat()
{
    for(int i=0; i<hang; i++)
    {
        for(int j=0; j<cot; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
matran matran::Tong(matran &mt)
{
    matran tong;
    tong.hang=hang; tong.cot=cot;
    if(hang==mt.hang && cot==mt.cot){
        for(int i=0; i<hang; i++)
        {
            for(int j=0; j<cot; j++){
                tong.a[i][j] = a[i][j] + mt.a[i][j];
            }
        }
        return tong;
    }else
        cout<<"Kich thuoc khong bang nhau";
}