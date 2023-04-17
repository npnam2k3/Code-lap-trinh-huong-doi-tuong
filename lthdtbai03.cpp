#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int *a,*b,n,n1=0,i1=0,count=0;
    ifstream fin("dayso.txt");
    fin>>n;
    a=new int[n];
    for(int i=0; i<n; i++){
        fin>>a[i];
        if(a[i]%2==0)
            count++;
    }
    b=new int[count];
    ofstream fout("ketqua-lthdtbai03.txt");
    for(int i=0; i<n; i++){
        if(a[i]%2==0){
            b[i1++]=a[i];
            n1++;
        }else{
            fout<<a[i]<<"\t";
        }
    }
    for(int i=0; i<n1; i++){
        fout<<b[i]<<"\t";
    }
    delete a;
    delete b;
    return 0;
}