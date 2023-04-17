#include<iostream>
#include<vector>
using namespace std;
class Transport
{
    private:
        string manufacturer, name;
        int year, speed;
    public:
        Transport(){}
        Transport(string manufacturer, string name, int year, int speed)
        :manufacturer(manufacturer),name(name),year(year),speed(speed)
        {

        }
        string getManufactuer()
        {
            return manufacturer;
        }
        string getName()
        {
            return name;
        }
        int getYear()
        {
            return year;
        }
        int getSpeed()
        {
            return speed;
        }
        void display()
        {
            cout<<"Manufacturer: "<<manufacturer<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Year Of Manufacturer: "<<year<<endl;
            cout<<"Speed: "<<speed<<endl;
        }
};

class Car :public Transport
{
    private:
        int numberSeat;
        string enginetype;
    public:
        Car(){}
        Car(string manufactuer, string name, int year, int speed, int numberSeat, string enginetype):
        Transport(manufactuer,name,year,speed),numberSeat(numberSeat),enginetype(enginetype)
        {

        }
        int getNumberSeat()
        {
            return numberSeat;
        }
        string getEngineType()
        {
            return enginetype;
        }
        double getSpeedBasic()
        {
            return (float)getSpeed()/getNumberSeat();
        }
        void display()
        {
            Transport::display();
            cout<<"Number Seat: "<<getNumberSeat()<<endl;
            cout<<"Engine Type: "<<getEngineType()<<endl;
            cout<<"Speed Basic: "<<getSpeedBasic()<<endl;
        }
        static vector<Car> getCarHaveMaxSpeedBasic(vector<Car> vt)
        {
            vector<Car> v;
            float max = vt[0].getSpeedBasic();
            for(int i=1; i<vt.size(); i++)
            {
                if(vt[i].getSpeedBasic() > max)
                    max=vt[i].getSpeedBasic();
            } 
            for(int i=0; i<vt.size(); i++)
            {
                if(max == vt[i].getSpeedBasic())
                    v.push_back(vt[i]);
            }
            return v;
        }
        static vector<Car> getCarHaveMaxSeat(vector<Car> vt)
        {
            vector<Car> v;
            float max=vt[0].numberSeat;
            for(int i=1; i<vt.size(); i++)
            {
                if(vt[i].numberSeat > max)
                    max =  vt[i].numberSeat;
            }
            for(int i=0; i<vt.size(); i++)
            {
                if(vt[i].numberSeat == max)
                    v.push_back(vt[i]);
            }
            return v;
        }
};
int main()
{
    vector<Car> vt;
    Car c1("VietNam", "vinfat", 2020, 400, 4, "diesel");
    Car c2("Korea", "Kia Morning", 1980, 200, 4, "petrol");
    Car c3("Japan", "Madaz 3", 1990, 500, 6, "auto");
    vt.push_back(c1);
    vt.push_back(c2);
    vt.push_back(c3);

    for(int i=0; i<vt.size(); i++)
    {
        vt[i].Car::display();
        cout<<"----------------"<<endl;
    }
    for(int i=0; i<Car::getCarHaveMaxSpeedBasic(vt).size(); i++)
    {
        cout<<"-------MAX SPEED---------"<<endl;
        Car::getCarHaveMaxSpeedBasic(vt)[i].display();
    }
    for(int i=0; i<Car::getCarHaveMaxSeat(vt).size(); i++)
    {
        cout<<"-------MAX SEAT-------"<<endl;
        Car::getCarHaveMaxSeat(vt)[i].display();
    }
    cout<<endl;
    return 0;
}