#include<iostream>
using namespace std;
class person{
    protected:
    string name;
    int age;
    public:
    void setage(int age){
        this->age = age;

    }void setname(string name){
        this->name = name;

    } void getage(){
        cout<<"age is:";
       cout<<age<<endl;

    }void getname(){
        cout<<"name is:";
       cout<<name<<endl;

    }

};
class student:public virtual person{
     protected:
    string course;
    int studentid;
    public:
    void setstudentid(int studentid){
        this->studentid = studentid;

    }void setcourse(string course){
        this->course = course;

    } void getstudentid(){
        cout<<"studentid is:";
       cout<<studentid<<endl;

    }void getcourse(){
        cout<<"course is:";
       cout<<course<<endl;

    }
};
class teacher:public virtual person{
     protected:
    string subjecttaught;
    int employeeid;
    public:
    void setemployeeid(int employeeid){
        this->employeeid =employeeid;

    }void setsubjecttaught(string subjecttaught){
        this->subjecttaught = subjecttaught;

    } void getemployeeid(){
        cout<<"employeeid is:";
       cout<<employeeid<<endl;

    }void getsubjecttaught(){
        cout<<"subjecttaught is:";
       cout<<subjecttaught<<endl;

    }
};
class researcher:public teacher,public student{
protected:
string researchtopic;
public:
void setresearchtopic( string researchtopic){
    this->researchtopic= researchtopic;
}
void display(){
    getname();
    getage();
    getstudentid();
    getcourse();
    getsubjecttaught();
    getemployeeid();
    cout<<"research topic:";
    cout<<researchtopic<<endl;
  
}

};

int main()
{
    researcher madhav;
    madhav.setage(19);
    madhav.setname("Madhav");
    madhav.setstudentid(1023160);
    madhav.setcourse("Btech");
    madhav.setsubjecttaught("chemistry");
    madhav.setemployeeid(104);
    madhav.setresearchtopic("flames");
    madhav.display();
 return 0;
}