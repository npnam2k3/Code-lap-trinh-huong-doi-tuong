#include<iostream>
#include<math.h>
using namespace std;
class Geometry
{
    public:
        virtual double perimeter() = 0;
        virtual double area() = 0;
        virtual void display()
        {
            cout<<"Perimeter: "<<perimeter()<<endl;
            cout<<"Area: "<<area()<<endl;
        }
};
class Traingle: public Geometry
{
    private:
        int a;
        int b; 
        int c;
    public:
        Traingle(){}
        Traingle(int a, int b, int c):a(a),b(b),c(c){}
        double perimeter()
        {
            return a+b+c;
        }
        double area()
        {
            double p = (double)(a+b+c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
};
class Circle: public Geometry
{
    private:
        int r;
    public:
        Circle(){}
        Circle(int r):r(r){}
        double perimeter()
        {
            return r*2*3.14;
        }
        double area()
        {
            return r*r*3.14;
        }
};
class Rectangle: public Geometry
{
    private:
        int h;
        int w;
    public:
        Rectangle(){}
        Rectangle(int h, int w):h(h),w(w){}
        double perimeter()
        {
            return (h+w)*2;
        }
        double area()
        {
            return h*w;
        }
};
int main()
{
    Geometry *g[3];
    g[0] = new Traingle(5,6,7);
    g[1] = new Circle(5);
    g[2] = new Rectangle(8,10);
    for(int i=0; i<3; i++)
    {
        switch(i)
        {
            case 0:
                cout<<"****Hinh tam giac****"<<endl;
                break;
            case 1:
                cout<<"****Hinh tron****"<<endl;
                break;
            case 2:
                cout<<"****Hinh chu nhat****"<<endl;
                break;
        }
        g[i]->display();
        cout<<endl;
    }
    cout<<endl;
    return 0;
}