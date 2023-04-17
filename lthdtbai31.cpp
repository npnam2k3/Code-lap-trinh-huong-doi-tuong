/* Cho tệp văn bản "daysonguyen-bai31.txt" chứa một dãy số nguyên,
trên tệp không có thông tin về số lượng số. Đọc từng số của dãy số từ tệp,
nếu là số nguyên tố thì đưa vào hàng đợi. Đưa ra màn hình dãy số đọc từ tệp và
dãy số nguyên tố trong hàng đợi. Yêu cầu cài đặt và sử dụng hàng đợi lưu trữ phân tán.*/
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

bool SoNguyenTo(int x);
class Queue
{
    private:
        struct Node{
            int infor;
            Node *link;
        } *F, *R;
    public:
        Queue();
        ~Queue();
        void CQInsert(int x);
        int CQDelete();
        bool isEmpty();
};

//chuong trinh chinh
int main()
{
    Queue Q;
    int x;
    ifstream fin("dayso-A.txt");
    cout<<"Day so doc tu tep la: \n";
    while(fin>>x)
    {
        if(SoNguyenTo(x))
        {
            Q.CQInsert(x);
        }
        cout<<x<<"  ";
    }
    cout<<"\nDay so trong hang doi la: \n";
    while(!Q.isEmpty())
    {
        cout<<Q.CQDelete()<<"  ";
    }
    cout<<endl;
    return 0;
}

//dinh nghia ham
Queue::Queue():F(NULL),R(NULL)
{

}

Queue::~Queue()
{
    while(F)
    {
        Node *P = F;
        F=F->link;
        delete P;
    }
}

void Queue::CQInsert(int x)
{
    //tao nut moi
    Node *N=new Node;
    N->infor = x;
    N->link = NULL;

    //Noi nut moi vao sau R
    if(F==NULL && R==NULL)
        F=N;
    else    
        R->link = N;

    //cho R tro sang nut moi
    R=N;
}

int Queue::CQDelete()
{
    //kiem tra rong
    if(F==NULL && R==NULL)
    {
        cout<<"Hang doi rong!";
        return 1;
    }

    //luu lai phan tu loai bo
    int tg = F->infor;
    Node *P = F;

    //cho F tro sang nut tiep theo
    if(F==R)
        F=NULL;
    else    
        F=F->link;
    
    //huy nut va tra ve phan tu loai bo
    delete P;
    return tg;
}

bool Queue::isEmpty()
{
    return F==NULL && R==NULL;
}

bool SoNguyenTo(int x)
{
    if(x<=1)    return false;
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i == 0)
            return false;
    }
    return true;
}