#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main(){
    float a,b,c;
    cout<<"CHUONG TRINH TINH CHU VI VA DIEN TICH HINH TAM GIAC\n";
    ifstream fin("tamgiac.txt");
    fin>>a>>b>>c;
    float p=(a+b+c)/2;
    float cv=a+b+c;
    float dt=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<"Chu vi hinh tam giac la: "<<cv<<endl;
    cout<<"Dien tich hinh tam giac la: "<<dt<<endl;
    ofstream fout("ketqua-lthdtbai01.txt");
    fout<<"Chu vi: "<<cv<<endl;
    fout<<"Dien tich: "<<dt<<endl;
    return 0;
}