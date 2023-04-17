#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void docMT(int *&V, int &m, int &n, char *tentep){
    ifstream fin(tentep);
    fin>>m>>n;
    V=new int[m*n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            fin>>V[i*n+j];
        }
    }
    fin.close();
}
void inMT(int *V, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<V[i*n+j]<<"  ";
        }
        cout<<endl;
    }
}
int* TichMT(int *&V1, int *&V2, int m, int p, int n){
    int *V3=new int[m*n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            V3[i*n+j]=0;
            for(int k=0; k<p; k++){
                V3[i*n+j] += V1[i*p+k] * V2[k*n+j];
            }
        }
    }
    return V3;
}
int main(){
    int *a,*b,*c,mA,pA,pB,nB;
    docMT(a,mA,pA,"matran-A.txt");
    docMT(b,pB,nB,"matran-B.txt");
    cout<<"Ma tran A: \n";
    inMT(a,mA,pA);
    cout<<"Ma tran B: \n";
    inMT(b,pB,nB);
    ofstream fout("matran-C.txt");
    c=TichMT(a,b,mA,pA,nB);
    fout<<mA<<"\t"<<nB<<endl;
    for(int i=0; i<mA; i++){
        for(int j=0; j<nB; j++){
            fout<<c[i*nB+j]<<"  ";
        }
        fout<<endl;
    }
    fout.close();
    cout<<"Ma tran C la: \n";
    inMT(c,mA,nB);
    return 0;
}  