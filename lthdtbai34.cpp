/**Cho tệp văn bản "daysonguyen-bai34.txt" chứa dãy số nguyên,
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp và lưu vào
danh sách liên kết kép (DSLKK) theo thứ tự giống như trên tệp. Đưa dãy số trong DSLKK ra màn hình
theo thứ tự từ trái sang phải và từ phải sang trái. Cho biết số phần tử có trong DSLKK.
Chèn phần tử x vào đầu danh sách. Xóa nút có phần tử bằng x. Tìm nút có phần tử bằng x.*/
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
// khai bao lop
class DList
{
    private:
        struct node
        {
            int infor;
            node *left, *right;
        } *L, *R;

    public:
        DList();
        ~DList();
        void lastInsert(int x);
        void display();
        void headInsert(int x);
        bool search(int x);
        bool remove(int x);
};
//===Chuong trinh chinh===
int main()
{
    DList Dl;
    int x, y;
    ifstream fin("dayso-A.txt");

    while (fin >> y)
    {
        Dl.lastInsert(y);
    }

    Dl.display();
    // cout<<"\nNhap vao gia tri can bo sung: ";
    // cin>>x;
    // Dl.headInsert(x);
    // cout<<"\nDanh sach sau khi bo sung la: \n";
    // Dl.display();
    cout << "\nNhap vao gia tri can tim: ";
    cin >> x;
    if (Dl.search(x))
    {
        cout << "\nDa tim thay phan tu co gia tri bang " << x;
        if (Dl.remove(x))
        {
            cout << "\nDa xoa phan tu co gia tri bang " << x;
            cout << "\nDanh sach sau khi xoa la: \n";
            Dl.display();
        }
    }
    else
        cout << "\nKhong tim thay phan tu co gia tri bang " << x;

    cout << endl;
    return 0;
}
// Dinh nghia ham
DList::DList() : L(NULL), R(NULL)
{
}

DList::~DList()
{
    while (L)
    {
        node *P = L;
        L = L->right;
        delete P;
    }
}

void DList::lastInsert(int x)
{
    // tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // them nut moi vao cuoi danh sach
    if (L == NULL)
        L = R = N;
    else
    {
        R->right = N;
        N->left = R;
        R = N;
    }
}

void DList::display()
{
    cout << "\nDay so tu trai sang phai la: \n";
    node *P = L;
    while (P)
    {
        cout << P->infor << " ";
        P = P->right;
    }
    cout << "\nDay so tu phai sang trai la: \n";
    node *Q = R;
    while (Q)
    {
        cout << Q->infor << " ";
        Q = Q->left;
    }
}

void DList::headInsert(int x)
{
    // tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // them vao dau danh sach
    if (L == NULL)
        L = R = N;
    else
    {
        N->right = L;
        L->left = N;
        L = N;
    }
}

bool DList::search(int x)
{
    node *P = L;
    while (P)
    {
        if (P->infor == x)
            return true;
        P = P->right;
    }
    return false;
}

bool DList::remove(int x)
{
    if (L==NULL && R==NULL)
        return false;
    node *P = L;
    while (P)
    {
        if (P->infor == x)
            break;
        else
        {
            P = P->right;
        }
    }
    if (P)
    {
        if (P == L && P == R)
        {
            L = R = NULL;
        }
        else if (P == L)
        {
            L = L->right;
            if(L)
                L->left = NULL;
        }
        else if (P == R)
        {
            R = R->left;
            if(R)
                R->right = NULL;
        }
        else
        {
            P->left->right = P->right;
            P->right->left = P->left;
        }
        delete P;
        return true;
    }
    return false;
}