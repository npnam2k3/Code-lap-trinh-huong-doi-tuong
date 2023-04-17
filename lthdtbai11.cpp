#include<iostream>
#include<fstream>
using namespace std;
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void sapxep(int *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i;j--){
            if(a[j]>a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}
int main(){
    int *a,n;
    ifstream fin("dayso.txt");
    fin>>n;
    a=new int[n];
    for(int i=0; i<n; i++){
        fin>>a[i];
    }
    sapxep(a,n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<"\t";
    }
    delete a;
    return 0;
}