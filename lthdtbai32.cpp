/*Cho tệp văn bản "daysonguyen-bai32.txt" chứa dãy số nguyên,
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản, lưu dãy số trong
danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.*/
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
        bool Search(int x);
        void show();
        bool remove(int x);
};
//chuong trinh chinh
int main()
{
    SList SL;
    ifstream fin("dayso-A.txt");

    //doc day so tu tep vao DSLKD
    int x;
    while(fin>>x)
    {
        SL.LastInsert(x);
    }

    cout<<"\nDay so trong DSLKD la: \n";
    SL.show();

    //tim va xoa x
    cout<<"\nNhap vao x: ";
    cin>>x;
    if(SL.Search(x))
    {
        cout<<"\nTim thay phan tu co gia tri bang "<<x<<" trong DSLKD";
        if(SL.remove(x))
        {
            cout<<"\nDa xoa phan tu co gia tri bang "<<x<<" trong DSLKD";
            cout<<"\nDSLKD sau khi xoa la: \n";
            SL.show();
        }
    }
    else
        cout<<"Khong tim thay phan tu co gia tri bang "<<x<<" trong DSLKD";
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
        F=F->link;
        delete P;
    }
}

void SList::LastInsert(int x)
{
    //tao nut moi 
    Node *N = new Node;
    N->infor = x;
    N->link = NULL;

    //noi nut moi vao cuoi danh sach
    if(F==NULL) F=N;
    else
    {
        //tim den nut cuoi
        Node *P = F;
        while(P->link)
        {
            P=P->link;
        }
        //noi nut moi vao sau nut cuoi
        P->link = N;
    }
}

bool SList::Search(int x)
{
    Node *P = F;
    while(P)
    {
        if(P->infor == x)   return true;
        else
        {
            P=P->link;
        }
    }
    //khong tim thay
    return false;
}

void SList::show()
{
    Node *P=F;
    while (P)
    {
        cout<<P->infor<<"  "; 
        P=P->link;
    }  
}

bool SList::remove(int x)
{
    //truong hop DSLKD rong
    if(F==NULL) return false;
    //tim nut M co gia tri bang x va nut P dung truoc nut M
    Node *M=F, *P;
    while(M)
    {
        if(M->infor == x) break;
        else P=M; M=M->link;
    }
    //xoa nut M
    if(M)
    {
        if(M==F) F=F->link;
        else P->link = M->link;
        delete M;
        return true;
    }
    //khong co phan tu co gia tri bang x
    return false;
}