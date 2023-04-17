#include<iostream>
#include<math.h>
using namespace std;
//khai bao ham
int BintoDec(char *&s, int n);
int main()
{
    int n;
    char *binary;
    cout<<"Nhap vao so bit: ";
    cin>>n;
    binary = new char[n];
    cout<<"Nhap vao xau nhi phan: ";
    cin>>binary;
    cout<<"Gia tri cua xau nhi phan "<<binary<<" la: "<<BintoDec(binary,n);
    delete[] binary;
    cout<<endl;
    return 0; 
}
//dinh nghia ham
int BintoDec(char *&s, int n)
{
    int decNumber = 0;
    int p=0;
    for(int i=n-1; i>=0; i--)
    {
            if(s[i] == '1')
                decNumber += pow(2,p);
            p++;
    }
    return decNumber;
}