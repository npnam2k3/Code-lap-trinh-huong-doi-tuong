#include<iostream>
#include<fstream>
using namespace std;
void doc(int **&V, int &m, int &n, char *tentep){
    ifstream fin(tentep);
    fin>>m>>n;
    V=new int *[m];
    for(int i=0; i<m; i++){
        V[i]=new int[n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            fin>>V[i][j];
        }
    }
}
void congMT(int **V1, int **V2, int m, int n){
    int **V3=new int *[m];
    for(int i=0; i<m; i++){
        V3[i]=new int[n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            V3[i][j] = V1[i][j]+V2[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<V3[i][j]<<" ";
        }
        cout<<endl;
    }
}
void inMT(int **V, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int **A, **B,**C, mA,nA,mB,nB;
    doc(A,mA,nA,"matran-A.txt");
    doc(B,mB,nB,"matran-B.txt");
    congMT(A,B,mA,nB);
    return 0;
}