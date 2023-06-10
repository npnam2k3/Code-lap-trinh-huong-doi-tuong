// Bài 35(lthdtbai35.cpp): Đọc danh sách n mặt hàng từ tệp văn bản "mathang.txt", lưu vào
// danh sách liên kết kép (DSLKK), mỗi mặt hàng có thông tin về mã hàng, tên hàng, số lượng, đơn giá.
// Đưa danh sách mặt hàng ra màn hình kèm theo số tiền của từng mặt hàng. Tính tổng số tiền của tất cả mặt hàng.
// Xóa mặt hàng có mã nhập vào từ bàn phím.
#include <iostream>
#include <fstream>
#include<strings.h>

using namespace std;

class DList
{
private:
    struct MatHang
    {
        char maMH[20];
        char tenMH[30];
        int soLuong;
        float donGia;
    };
    struct Node
    {
        MatHang infor;
        Node *Left, *Right;
    };
    Node *L, *R;

public:
    DList();
    ~DList();
    void DLLastInsert(MatHang x);
    bool DLDelete(char *maMH);
    void Display();
};
// Khai bao ham
int main()
{
    cout << endl;
    return 0;
}
// Dinh nghia ham
DList::DList():L(NULL),R(NULL)
{
}

DList::~DList()
{
    while(L)
    {
        Node *P = L;
        L=L->Right;
        if(L)
        {
            L->Left=NULL;
        }
        delete P;
    }
}

void DList::DLLastInsert(MatHang x)
{
    //Tạo nút mới
    Node *P = new Node;
    P->infor = x;
    P->Left = NULL;
    P->Right = NULL;

    //Trường hợp danh sách rỗng
    if(L==NULL && R==NULL)
    {
        L=R=P;
        return;
    }

    //trường hợp còn lại, thêm vào cuối danh sách
    P->Left = R;
    R->Right = P;
    R=P;
}

bool DList::DLDelete(char *maMH)
{
    //trường hợp danh sách rỗng
    if(L==NULL && R==NULL)
    {
        return false;
    }

    //tìm nút M có mã mặt hàng nhập vào
    Node *M = L, *P;
    while(M)
    {
        if(strcasecmp(maMH,M->infor.maMH)) 
            break;
        else
        {
            // P = M;
            M = M->Right;
        }
    }

    //xóa nút M
    if(M)
    {
        //danh sách chỉ còn 1 nút
        if(M==L && M==R) L=R=NULL;
        //M là nút cực trái
        else if(M==L)
        {
            L=L->Right;
            L->Left = NULL;
        } 
        //M là nút cực phải
        else if(M==R)
        {
            R=R->Left;
            R->Right=NULL;
        }
        //còn lại
        else
        {
            M->Left->Right = M->Right;
            M->Right->Left = M->Left;
            delete M;
            return true;
        }
    }
    //không tìm thấy phần tử có mã nhập vào
    return false;
}

void DList::Display()
{
    Node *P = L;
    while(P)
    {
        cout<<"Ma mat hang: "<<P->infor.maMH<<endl;
        cout<<"Ten mat hang: "<<P->infor.tenMH<<endl;
        cout<<"So luong: "<<P->infor.soLuong<<endl;
        cout<<"Don gia: "<<P->infor.donGia<<endl;
        P=P->Right;
    }
}