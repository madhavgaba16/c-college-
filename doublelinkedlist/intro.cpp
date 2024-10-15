class node{
    public:
    int data;
    node* next ;
     node* prev;
     node(int value){
        data = value;
        next = NULL;
        prev = NULL;
        
     }
}