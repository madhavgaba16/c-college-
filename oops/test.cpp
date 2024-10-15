    #include<iostream>
    using namespace std;
    class base{
    protected:
    int i ;
    public:
    base(){
        cout<<"constructor called base"<<endl;

    }
    base(int x){
        i = x;
        cout<<"constructor called base i is set "<<endl;
    }
    };
    class derived:public base{
        int x ;
        public :
        derived(){
        cout<<"constructor called derived "<<endl; 
        }
        // derived(int f):base(f){
        //    cout<<"constructor called derived base set  "<<endl; 
        // }
        derived(int y){
        bool a;
            cout <<"what you want to set "<<endl;
            cin>> a;
            if(a==1){
                base(y);
                cout<<"constructor called derived base  set  "<<endl; 
            }
            else{
            x = y;
            cout<<"constructor called derived derived  set  "<<endl; 
            }
        }
        derived(int y,int f ) :base(f){
            x = y;
            cout<<"constructor called derived derived  set base set   "<<endl; 
        }

    };
    int main()
    {
        derived obj(10);
    return 0;
    }