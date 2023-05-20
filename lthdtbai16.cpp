#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>

using namespace std;

class Hinhtron
{
    private:
        float r;
        char mauNen[7];
    public:
        void thietlapR(float r);
        void thietlapMauNen(const char *mauNen);
        void Hien();
        float tinhDT();
        float tinhCV();
        int layMaMau();
};
int main()
{
    ifstream fin("hinhtron.txt");
    float tongCV=0, tongDT=0, r;
    int demMau[4]={0}, kt=0;
    char tenMau[4][7] = {"Xanh", "Do", "Tim", "Vang"}, mauNen[7];

    int n;
    fin>>n;

    Hinhtron *hinhTron = new Hinhtron[n];
    for(int i=0; i<n; i++)
    {
        fin>>r>>mauNen;
        hinhTron[i].thietlapR(r);
        hinhTron[i].thietlapMauNen(mauNen);
        cout<<"\nBan kinh, Mau nen, Dien tich va chu vi cua hinh tron la: ";hinhTron[i].Hien();
        tongCV+=hinhTron[i].tinhCV();
        tongDT+=hinhTron[i].tinhDT();

        //dem so luong mau cua n hinh tron
        kt=hinhTron[i].layMaMau();
        if(kt>0 && kt<=4)
            demMau[kt-1]++;
    }
    cout<<"\nTong chu vi cua "<<n<<" hinh tron la: "<<tongCV;
    cout<<"\nTong dien tich cua "<<n<<" hinh tron la: "<<tongDT;

    for(int i=0; i<4; i++){
        cout<<"\nCo "<<demMau[i]<<" mau "<<tenMau[i];
    }
    delete []hinhTron;
    cout<<endl;
    return 0;
}

void Hinhtron::thietlapR(float r)
{
    this->r=r;
}

void Hinhtron::thietlapMauNen(const char *mauNen)
{
    strcpy(this->mauNen,mauNen);
}

void Hinhtron::Hien()
{
    cout<<"Ban kinh: "<<r;
    cout<<"\nMau nen: "<<mauNen;
    cout<<"\nChu vi: "<<tinhCV();
    cout<<"\nDien tich: "<<tinhDT();
}

float Hinhtron::tinhDT()
{
    return 3.14*r*r;
}

float Hinhtron::tinhCV()
{
    return 2*3.14*r;
}

int Hinhtron::layMaMau()
{
    if(strcasecmp(mauNen, "Xanh")==0) return 1;
    if(strcasecmp(mauNen, "Do")==0) return 2;
    if(strcasecmp(mauNen, "Tim")==0) return 3;
    if(strcasecmp(mauNen, "Vang")==0) return 4;
    return -1;
}