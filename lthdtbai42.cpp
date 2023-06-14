/** Tính diện tích các hình: Hình chữ nhật biết 2 cạnh a,b;
hình tam giác biết 3 cạnh a,b,c; hình tròn biết bán kính r, hình trụ biết bán kính r và chiều cao h.
Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo dài với chiều cao h.
Nhập vào một số hình, trong đó có cả hình chữ nhật, hình tam giác, hình tròn và hình trụ.
Đưa ra diện tích các hình đã nhập. Y/c cài đặt đa hình động và lớp trừu tượng; viết 1 hàm
lựa chọn hình, nhập kích thước cho hình và trả về hình đã nhập; viết 1 hàm đưa ra
diện tích của một hình truyền vào qua đối số.*/
#include<iostream>
#include<math.h>
using namespace std;

//Khai bao lop
class Hinh
{
    private:

    public:
        virtual void Nhap()=0;
        virtual float tinhDT()=0;
};

class HinhCN:public Hinh
{
    private:
        float a,b;
    public:
        void Nhap();
        float tinhDT();
};

class HinhTG:public Hinh
{
    private:
        float a,b,c;
    public:
        void Nhap();
        float tinhDT();
};

class HinhTron:public Hinh
{
    private:
        float r;
    public:
        void Nhap();
        float tinhDT();
        float tinhCV();
};

class HinhTru:public HinhTron
{
    private:
        float h;
    public:
        void Nhap();
        float tinhDT();
};

//Khai bao ham thong thuong
Hinh* NhapKT();
void HienDT(Hinh *h);

//===chuong trinh chinh===
int main()
{
    //Khai bao mang con tro lop co so Hinh
    Hinh *a[100];
    char traloi;
    int n=0;

    do{
        //Nhap kich thuoc
        a[n++]=NhapKT();
        cout<<"\nCo muon nhap tiep khong(c/k): ";
        cin>>traloi;
    }while(traloi == 'c' || traloi=='C');

    //dua ra dien tich cac hinh da nhap
    cout<<"\nDien tich cac hinh da nhap la: ";
    for(int i=0; i<n; i++)
    {
        cout<<"\nHinh thu "<<i+1<<" co ";
        HienDT(a[i]);
    }
    cout<<endl;
    return 0;
}
//Dinh nghia ham
void HinhCN::Nhap()
{
    cout<<"Nhap chieu dai va chieu rong: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

void HinhTG::Nhap()
{
    do{
        cout<<"Nhap 3 canh tam giac: ";
        cin>>a>>b>>c;
        if(a+b<=c || b+c<=a || a+c<=b)
        {
            cout<<"\n3 canh khong phai tam giac! Nhap lai: \n";
        }
    }while(a+b<=c || b+c<=a || a+c<=b);
}

float HinhTG::tinhDT()
{
    if(a+b>c && b+c>a && a+c>b)
    {
        float p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    return 0;
}

void HinhTron::Nhap()
{
    cout<<"\nNhap ban kinh: ";
    cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

void HinhTru::Nhap()
{
    //Nhap vao ban kinh ke thua tu lop hinh tron
    HinhTron::Nhap();
    cout<<"\nNhap vao chieu cao: ";
    cin>>h;
}

float HinhTru::tinhDT()
{
    return HinhTron::tinhDT()*2 + HinhTron::tinhCV()*h;
}

//Dinh nghia ham thong thuong
Hinh* NhapKT()
{
    Hinh *h;
    char chon;
    cout<<"\nNhap vao lua chon (1-HinhCN, 2-HinhTG, 3-HinhTron, 4-HinhTru): ";
    cin>>chon;
    switch(chon)
    {
        case '1':
            h=new HinhCN;
            break;
        case '2':
            h=new HinhTG;
            break;
        case '3':
            h=new HinhTron;
            break;
        case '4':
            h=new HinhTru;
            break;
        default:
            h=new HinhCN;
    }
    //dung da hinh dong de nhap kich thuoc cho doi tuong da tao
    h->Nhap();

    //tra ve hinh da nhap kich thuoc
    return h;
}

void HienDT(Hinh *h)
{
    //Dung da hinh dong de dua ra dien tich 
    cout<<"dien tich la: "<<h->tinhDT();
}