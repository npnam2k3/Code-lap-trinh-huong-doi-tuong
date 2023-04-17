/*Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
Ngăn xếp sử dụng cấu trúc lưu trữ phân tán với phần tử là ký tự.*/
#include<iostream>
#include<stdio.h>
using namespace std;

class Stack
{
    private:
        struct Node
        {
            int infor;
            Node *link;
        } *T;   
    public:
        Stack();
        ~Stack();
        void push(int x);
        int pop();     
        bool isEmpty();
};
int main()
{
    Stack S;
    int n;
    cout<<"Nhap n: ";cin>>n;
    while(n)
    {
        S.push(n%16);
        n/=16;
    }

    cout<<"So hex la: ";
    while(!S.isEmpty())
    {
        int du = S.pop();
        if(du<10)cout<<du;
        else printf("%c",du+55);
    }
    cout<<endl;
    return 0;
}
Stack::Stack():T(NULL)
{

}
Stack::~Stack()
{
    Node *P;
    while(T)
    {
        P=T;
        T=T->link;
        delete P;
    }
}
void Stack::push(int x)
{
    //tao nut moi
    Node *N=new Node;
    N->infor=x;
    N->link=NULL;

    //Noi nut moi len tren nut T
    N->link = T;

    //cho T tro len nut moi
    T = N;
}
int Stack::pop()
{
    //kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return 1;
    }

    // luu lai phan tu o dinh
    int tg=T->infor;
    Node *P = T;

    //cho T tro xuong nut duoi
    T = T->link;
    //xoa nut va tra ve phan tu o dinh
    delete P;
    return tg;
}
bool Stack::isEmpty()
{
    return T==NULL;
}