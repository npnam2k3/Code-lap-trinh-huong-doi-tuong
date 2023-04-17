#include<iostream>
using namespace std;
int UCLN(int a, int b){
    while (a!=b)
    {
        if(a>b)
            a-=b;
        else    
            b-=a;
    }
    return a;
}
int main(){
    int a,b;
    cout<<"Nhap vao a:";
    cin>>a;
    cout<<"Nhap vao b: ";
    cin>>b;
    cout<<"UCLN cua hai so nguyen duong a va b la: "<<UCLN(a,b)<<endl;
    return 0;
}