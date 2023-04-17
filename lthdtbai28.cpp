/* Nhập vào một số nguyên dương, đưa ra số nhị phân tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang nhị phân.
Ngăn xếp sử dụng cấu trúc lưu trữ kế tiếp.*/
#include<iostream>
#include<stdio.h>
using namespace std;

class Stack
{
    private:
        enum{size=32};
        int S[size];
        int T;
    public:
        Stack();
        void push(int x);
        int pop();
        bool isEmpty();
};
int main()
{
    Stack S;
    int n;
    cout<<"Nhap vao so nguyen duong: ";cin>>n;
    while(n)
    {
        S.push(n%2);
        n/=2;
    }
    cout<<"So nhi phan tuong ung la: ";
    while(!S.isEmpty())
    {
        cout<<S.pop();
    }
    cout<<endl;
    return 0;
}
Stack::Stack():T(-1)
{

}
void Stack::push(int x)
{
    if(T==size-1)
    {
        cout<<"Ngan xep day!";
        return;
    }
    S[++T] = x;
}
int Stack::pop()
{
    if(T==-1)
    {
        cout<<"Ngan xep rong!";
        return 1;
    }
    return S[T--];
}
bool Stack::isEmpty()
{
    return T==-1;
}