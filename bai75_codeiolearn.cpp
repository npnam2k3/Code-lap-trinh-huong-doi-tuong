#include<iostream>
#include<vector>
using namespace std;
class Person
{
    private:
        string name;
        int age;
        string add;
        string tel;
        string sex;
    public:
        Person(){}
        Person(string name, int age, string add, string tel, string sex):
        name(name), age(age), add(add), tel(tel),sex(sex){}
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
        string getAdd()
        {
            return add;
        }
        string getTel()
        {
            return tel;
        }
        string getSex()
        {
            return sex;
        }
        virtual void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"sex: "<<sex<<endl;
            cout<<"Add: "<<add<<endl;
            cout<<"Tel: "<<tel<<endl;
        }
        virtual long salary() = 0;
        static vector<Person*> findPerson(vector<Person *> p)
        {
            vector<Person *> v;
            for(int i=0; i<p.size(); i++)
            {
                if(p[i]->add == "HN")
                    v.push_back(p[i]);
            }
            return v;
        }
};
class EmployeePT: public Person
{
    private:    
        int hour;
        long money;
    public:
        EmployeePT(): Person(){}
        EmployeePT(string name, int age, string add, string tel, string sex, int hour, long money):
        Person(name, age, add, tel, sex), hour(hour), money(money){}
        int getHour()
        {
            return hour;
        }
        long getMoney()
        {
            return money;
        }
        virtual void display()
    	{
    		cout << "Employee Part Time" << endl;
    		Person::display();
    		cout << "Hour: " << hour << endl;
    		cout << "Money: " << money << endl;
    		cout << "Salary: " << salary() << endl;
    	}
        long salary()
        {
            return long(hour) * money;
        }
        static vector<EmployeePT> getMaxSalary(vector<EmployeePT> pt)
        {
            vector<EmployeePT> v;
            long max = pt[0].salary();
            for(int i=1; i<pt.size(); i++)
            {
                if(pt[i].salary() > max)
                    max=pt[i].salary();
            }
            for(int i=0; i<pt.size(); i++)
            {
                if(pt[i].salary() == max)
                    v.push_back(pt[i]);
            }
            return v;
        }
            
        
};
class EmployeeFT: public Person
{
    private:
        int day;
        long money;
    public:
        EmployeeFT() : Person(){}
        EmployeeFT(string name, int age, string add, string tel, string sex, int day, int money):
        Person(name, age, add, tel, sex), day(day), money(money){}
        int getDay()
        {
            return day;
        }
        long getMoney()
        {
            return money;
        }
        long salary()
        {
            return long(day) * money;
        }
        void display()
    	{
    		cout << "Employee Full Time" << endl;
    		Person::display();
    		cout << "Day: " << day << endl;
    		cout << "Money: " << money << endl;
    		cout << "Salary: " << salary() << endl;
    	}
        static vector<EmployeeFT> getMaxSalary(vector<EmployeeFT> ft)
        {
            vector<EmployeeFT> v;
            long max=ft[0].salary();
            for(int i=1; i<ft.size(); i++)
            {
                if(ft[i].salary() > max)
                    max=ft[i].salary();
            }
            for(int i=0; i<ft.size(); i++)
            {
                if(ft[i].salary() ==  max)
                    v.push_back(ft[i]);
            }
            return v;
        }
};
int main()
{
    Person *p[1];
	p[0] = new EmployeePT("Nam", 18, "HN", "0123", "Nu", 2, 100);
	p[1] = new EmployeeFT("Nam", 19, "HCM", "0123", "Nu", 25, 200);
	
	p[0]->display();
	cout << endl;
	p[1]->display();
	cout << endl;
	
	
	vector<Person*> s;
	s.push_back(new EmployeePT("Nam1", 20, "HN", "01234", "Nu", 3, 300));
	s.push_back(new EmployeeFT("Nam1", 21, "HCM", "01234", "Nu", 26, 400));
	
	for(int i=0; i< Person::findPerson(s).size(); i++)
	{
		Person::findPerson(s)[i]->display();
		cout << endl;
	}
	
	
	vector<EmployeePT> e;
	e.push_back(EmployeePT("Nam2", 22, "HN", "012345", "Nu", 4, 500));
	e.push_back(EmployeePT("Nam2", 23, "HCM", "012345", "Nu", 5, 600));
	e.push_back(EmployeePT("Nam2", 24, "HN", "012345", "Nu", 5, 600));
	
	for(int i=0; i< EmployeePT::getMaxSalary(e).size(); i++)
	{
		EmployeePT::getMaxSalary(e)[i].display();
		cout << endl;
	}
	
	
	vector<EmployeeFT> v;
	v.push_back(EmployeeFT("Nam3", 25, "HN", "0123456", "Nu", 27, 700));
	v.push_back(EmployeeFT("Nam3", 26, "HCM", "0123456", "Nu", 28, 800));
	v.push_back(EmployeeFT("Nam3", 27, "HN", "0123456", "Nu", 28, 800));
	
	for(int i=0; i< EmployeeFT::getMaxSalary(v).size(); i++)
	{
		EmployeeFT::getMaxSalary(v)[i].display();
		cout << endl;
	}
    cout<<endl;
    return 0;
}