/* Đọc vào một dãy số nguyên từ tệp văn bản, trong đó có cả số dương và số âm.
Sử dụng hàng đợi lưu trữ kế tiếp theo kiểu quay vòng để tách, đưa ra màn hình đồng thời
ghi ra tệp văn bản dãy các số dương và dãy các số âm.
*/
#include<iostream>
#include<fstream>
using namespace std;

class Queue
{
    private:
        enum{size=50};
        int Q[size];
        int F,R;
    public:
        Queue();
        void CQInsert(int x);
        int CQDelete();
        bool isEmpty();
};

int main()
{
    Queue Q;
    int n,a[100];
    ifstream fin("dayso.txt");
    ofstream fout("ketqua-lthdtbai30.txt");

    fin>>n;
    for(int i=0; i<n; i++)
    {
        fin>>a[i];
    }

    cout<<"Day so doc vao tu tep la: \n";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;

    fout<<"Cac so duong la: \n";
    for(int i=0; i<n; i++)
    {
        if(a[i]>=0)
        {
            Q.CQInsert(a[i]);
            fout<<a[i]<<"  ";
        }
    }

    fout<<"\nCac so am la: \n";
    for(int i=0; i<n; i++)
    {
        if(a[i]<0)
        {
            Q.CQInsert(a[i]);
            fout<<a[i]<<"  ";
        }
    }

    cout<<"Hang doi la: \n";
    while(!Q.isEmpty())
    {
        cout<<Q.CQDelete()<<"  ";
    }
    cout<<endl;
    return 0;
}
Queue::Queue():F(-1),R(-1)
{

}

void Queue::CQInsert(int x)
{
    //kiem tra day
    if(F==0 && R==size-1 || F==R+1)
    {
        cout<<"Hang doi day!";
        return;
    }

    //tang R len 1
    if(F==-1 && R==-1) //khong duoc viet (F==R==-1)
        F=R=0;
    else if(R==size-1)
        R=0;
    else    
        R++;
    //gan x vao hang doi o vi tri R
    Q[R] = x;
}

int Queue::CQDelete()
{
    //kiem tra rong
    if(F==-1 && R==-1)
    {
        cout<<"Hang doi rong!";
        return 1;
    }
    //luu lai phan tu loai bo
    int tg = Q[F];

    //tang F len 1
    if(F==R)
        F=R=-1;
    else if(F==size - 1)
        F=0;
    else F++;
    return tg;
}

bool Queue::isEmpty()
{
    return F==-1 && R==-1;
}
