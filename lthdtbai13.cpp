#include<iostream>
#include<fstream>
using namespace std;
void doc(int *&V,char *tentep, int &n){
    ifstream fin(tentep);
    fin>>n;
    V=new int[n];
    for(int i=0; i<n; i++){
        fin>>V[i];
    }
    fin.close();
}
int main(){
    int *a,*b,*c,n,iA=0,iB=0,iC=0;
    doc(a,"dayso-A.txt",n);
    doc(b,"dayso-B.txt",n);
    int nC=n*2;
    c=new int[nC];
    while(iC<nC){
        if(iA>=n)
            c[iC++]=b[iB++];
        else if(iB>=n)
            c[iC++]=a[iA++];
        else if(a[iA]<b[iB])
            c[iC++]=a[iA++];
        else    
            c[iC++]=b[iB++];
    }
    cout<<"Day so sau khi tron la: \n";
    for(int i=0; i<nC; i++){
        cout<<c[i]<<"\t";
    }
    return 0;
}