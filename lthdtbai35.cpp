/**Đọc danh sách n mặt hàng từ tệp văn bản "mathang.txt", lưu vào
danh sách liên kết kép (DSLKK), mỗi mặt hàng có thông tin về mã hàng, tên hàng, số lượng, đơn giá.
Đưa danh sách mặt hàng ra màn hình kèm theo số tiền của từng mặt hàng. Tính tổng số tiền của tất cả mặt hàng.
Xóa mặt hàng có mã nhập vào từ bàn phím.*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include<strings.h>

using namespace std;
struct matHang
{
    char maMH[11];
    char tenMH[100];
    int soLuong;
    float donGia;
};
// khai bao lop danh sach lien ket kep
class DList
{
private:
    struct node
    {
        matHang infor;
        node *left, *right;
    } *L, *R;

public:
    DList();
    ~DList();
    void lastInsert(matHang x);
    void display();
    float getSum();
    bool remove(char *x);
};
//===chuong trinh chinh===
int main()
{
    ifstream fin("mathang.txt");
    DList list;

    // khai bao bien
    matHang x;
    char maMH[11];
    char tg[2];
    int n;

    fin>>n;
    fin.ignore();
    for(int i=0; i<n; i++)
    {
        //doc ki tu enter de dua con tro chuot xuong dong
        fin.getline(tg, sizeof(tg));

        //doc thong tin mat hang thu i vao x
        fin.getline(x.maMH,sizeof(x.maMH), '\t');
        fin.getline(x.tenMH, sizeof(x.tenMH), '\t');
        fin>>x.soLuong>>x.donGia;
        fin.ignore();

        //dua x vao dslkk
        list.lastInsert(x);
    }
    // cout<<"Nhap vao so luong mat hang: ";cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "\nNhap vao ma mat hang: ";scanf(" ");
    //     cin.getline(x.maMH, sizeof(x.maMH));
    //     cout << "\nNhap vao ten hang: ";
    //     cin.getline(x.tenMH, sizeof(x.tenMH));
    //     cout << "\nNhap vao so luong: ";
    //     cin >> x.soLuong;
    //     cout << "\nNhap vao don gia: ";
    //     cin >> x.donGia;
    //     list.lastInsert(x);
    // }
    cout << "\nDanh sach mat hang trong DSLKK la: ";
    list.display();
    // cout<<"\nTong tien la: "<<list.getSum();
    // cout<<"\nNhap vao ma can xoa: ";cin>>maMH;
    // if(list.remove(maMH))
    // {
    //     cout<<"Da xoa thanh cong";
    //     cout<<"\nDanh sach sau khi xoa la: ";
    //     list.display();
    // }
    // else 
    //     cout<<"\nKhong tim thay ma";
    cout << endl;
    return 0;
}
// dinh nghia ham
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

void DList::lastInsert(matHang x)
{
    // tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // noi nut moi vao cuoi danh sach
    if (R == NULL)
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
    node *P = L;
    while (P)
    {
        cout << "\n\nMa mat hang: " << P->infor.maMH;
        cout << "\nTen mat hang: " << P->infor.tenMH;
        cout << "\nSo luong la: " << P->infor.soLuong;
        cout << "\nDon gia la: " << P->infor.donGia;
        cout << "\nThanh tien: " << P->infor.soLuong * P->infor.donGia;

        P = P->right;
    }
}

float DList::getSum()
{
    float sum = 0;
    node *P = L;
    while (P)
    {
        sum += P->infor.donGia * P->infor.soLuong;
        P = P->right;
    }
    return sum;
}

bool DList::remove(char *x)
{
    // truong hop danh sach rong
    if (R == NULL)
        return false;
    node *P = L;
    while (P)
    {
        if (strcasecmp(P->infor.maMH,x)==0)
            break;
        P = P->right;
    }
    if (P)
    {
        if (P == L && P == R)
            L = R = NULL;
        else if (P == L)
        {
            L = L->right;
            if (L)
                L->left = NULL;
        }
        else if (P == R)
        {
            R = R->left;
            if (R)
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