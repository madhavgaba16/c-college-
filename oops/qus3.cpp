#include<iostream>
using namespace std;
class person{
protected:
 string name;
 int age ;
 public:
  void setname(string n){
    name = n;
  }
  void setage(int r ){
    age = r;
  }
  void getname(){
    cout<<name<<endl;
  }
  void getage(){
    cout<<age <<endl;
  }
};
class student: virtual public person{
 protected:
 int studentid;
 string course;
 public:
  void setcourse(string n){
   course = n;
  }
  void setid(int r ){
  studentid = r;
  }
  void getcourse(){
    cout<<course<<endl;
  }
  void getid(){
    cout<<studentid <<endl;
  }


};
class teacher:virtual public person{
    protected:
    int employeeid;
    string subject;
    public:
    void setsubject(string n){
   subject = n;
  }
  void setid(int r ){
   employeeid = r;
  }
  void getsubject(){
    cout<<subject<<endl;
  }
  void getid(){
    cout<<employeeid <<endl;
  }

};
class research:public student,public teacher{
 public:
 string topic;

 void getid(){
     teacher::getid();
     }
    void setid(int n){
      teacher::setid(n);
     }
};
int main()
{
  research s1;
  s1.setname("student1");
  s1.setage(27);
  s1.setid(28);
  s1.setcourse("chemistry");
  s1.setsubject("flames");
  s1.topic= "chemicals";
  s1.getname();
  s1.getage();
  s1.getid();
  s1.getcourse();
  s1.getsubject();
  cout<<s1.topic<<endl;

 return 0;
}
