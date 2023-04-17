/*Sử dụng danh sách liên kết đơn P để lưu trữ dãy số nguyên
theo thứ tự đọc vào từ tệp văn bản "daysonguyen-bai33.txt", trên tệp không có thông tin
về số phần tử của dãy số. Tạo danh sách liên kết đơn Q bao gồm các phần tử dữ liệu của P
nhưng theo thứ tự đảo ngược. Xóa một nút trên DSLK đơn P mà có phần tử dữ liệu bằng
x nhập vào từ bàn phím. Đưa ra màn hình dãy số nguyên trong danh sách liên kết đơn*/
#include<iostream>
#include<fstream>
using namespace std;

//khai bao lop
class SList
{
    private:
        struct Node
        {
            int infor;
            Node *link;
        } *F;
    public:
        SList();
        ~SList();
        void LastInsert(int x);
        void FirstInsert(int x);
        bool remove(int x);
        void show();
        void reverseSList(SList &P);
};
//chuong trinh chinh
int main()
{
    SList Q,P;
    ifstream fin("dayso-A.txt");

    //doc day so tu tep vao DSLKD
    int x;
    while(fin>>x)
        P.LastInsert(x);
    cout<<"\nDay so trong DSLKD P la: \n";
    P.show();

    //dao nguoc danh sach P trong Q
    Q.reverseSList(P);
    cout<<"\nDay so dao nguoc cua P trong Q la: \n";
    Q.show();

    //xoa nut co gia tri bang x nhap vao tu ban phim
    cout<<"\nNhap vao x: ";cin>>x;
    if(P.remove(x))
    {
        cout<<"\nDa xoa phan tu co gia tri bang "<<x<<" trong DSLKD P";
        cout<<"\nDSLKD P sau khi xoa la: \n";
        P.show();
    }
    cout<<endl;
    return 0;
}

//dinh nghia ham
SList::SList():F(NULL)
{

}

SList::~SList()
{
    while(F)
    {
        Node *P = F;
        F = F->link;
        delete P;
    }
}

void SList::LastInsert(int x)
{
    //tao nut moi
    Node *N = new Node;
    N->infor = x;
    N->link = NULL;

    //Noi nut moi vao sau DSLKD
    if(F==NULL) F=N;
    else
    {
        //tim nut cuoi DSLKD
        Node *P = F;
        while(P->link)
        {
            P=P->link;
        }

        //noi nut N vao sau nut cuoi
        P->link = N;
    }
}

void SList::FirstInsert(int x)
{
    //tao nut moi
    Node *N = new Node;
    N->infor = x;
    N->link=NULL;

    //noi nut moi vao truoc DSLKD
    N->link = F;
    F=N; 
}

void SList::show()
{
    Node *P = F;
    while(P)
    {
        cout<<P->infor<<"  ";
        P=P->link;
    }
}

bool SList::remove(int x)
{
    //truong hop danh sach rong
    if(F==NULL) return false;

    //tim den nut M co gia tri bang x va nut P dung truoc nut M
    Node *M=F, *P;
    while(M)
    {
        if(M->infor == x)   break;
        else{
            P = M;
            M = M->link;
        }
    }

    //xoa nut M
    if(M)
    {
        //ngat ket noi voi nut M
        if(M==F)    F=F->link;
        else{
            P->link = M->link;
        }
        delete M;
        //tra ve true de bao xoa thanh cong
        return true;
    }
    //khong tim thay nut M
    return false;
}
void SList::reverseSList(SList &P)
{
    Node *M = P.F;
    while(M)
    {
        SList::FirstInsert(M->infor);
        M=M->link;
    }
}