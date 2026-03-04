#include<iostream>
using namespace std ;

int main(){

    double a , b ;
    char ch ;
    bool flag = 0 ;

    do{
        cout<<"Enter The First Number : ";
        cin>>a ;
        cout<<"Enter The Second Number : ";
        cin>>b ;
        cout<<"Enter The Operation :( + , - , * , / , % ) : ";
        cin>>ch ;
    
        switch( ch ){
    
            case '+' :
                cout<<"Addition : "<<a<<" + "<<b<<" = "<<a+b<<endl ;
                break ;
            
            case '-' :
                cout<<"Substraction : "<<a<<" - "<<b<<" = "<<a-b<<endl ;
                break ;
    
            case '*' :
                cout<<"Multiplication : "<<a<<" * "<<b<<" = "<<a*b<<endl ;
                break ;
    
            case '/' :
                cout<<"Division : "<<a<<" / "<<b<<" = "<<a/b<<endl ;
                break ;
    
            case '%' :
                cout<<"Modulo : "<<a<<" % "<<b<<" = "<<(int)a%(int)b<<endl ;
                break ;
    
            default : 
                cout<<"Enter Valid Operation : "<<endl;
                break ;
            
        }
        cout<<"Do you Want To Continue :(yes=1/ No=0) : ";
        cin>>flag ;
    }while(flag ==1);
    

}