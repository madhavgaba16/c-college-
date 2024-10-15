#include<iostream>
using namespace std;
class player{
    protected:
    string name;
    int score;
    public:
    void set_player(string r ,int s){
        name = r;
        score = s;
    }
    void display(){
        cout<<"player name:"<<name<<endl;
         cout<<"player score:"<<score<<endl;
        
    }
};
class team{
    protected:
    player players[3];
   int sum;
     int count;
    public:
    team(){
        sum =0 ;
        count =0 ;
    }
   
    set_player(string r,int s ){
     
        sum+= s;
        players[count].set_player(r,s);
           count++;
    }
    void display(){
        for(int i =0;i<count;i++){
            players[i].display();
        }

    }
   void add_score(){
      cout<< sum<<endl; 
    }
    friend void comp_score(team,team);

};

void comp_score(team a,team b ){
    // cout<<"the winning team is:";
    if(a.sum>b.sum){
        
      cout<<"wining team is"<<endl;
      a.display();
    
    }
    else{
    cout<<"wining team is"<<endl;
      b.display();
    }
}
int main()

{
    team a ;
    a.set_player("shaurya", 9);
    a.set_player("madhav", 10);
    a.set_player("ishan", 7);
    team b;
    b.set_player("samir", 8);
    b.set_player("mehul", 05);
    b.set_player("tejas", 4);
     cout << "Team A Players:" << endl;
    a.display();
    cout<<"total score";
    a.add_score();
     cout << "Team b Players:" << endl;

    b.display();
     cout<<"total score";
    b.add_score();
   comp_score(a,b);
 return 0;
}