#include<iostream>
using namespace std ;

void Prime( int n ){
    bool flag = 1 ;

    if(n == 1 || n==0){
        cout<<n<<" Is Neither Prime Nor Composite."<<endl;
        exit(0) ;
    }
    else if(n<0){
        cout<<"Enter Valid Positive Number."<<endl;
        exit(0) ;
    }
    else{
        for(int i = 2 ; i<n ; i++ ){
            if( n%i == 0 ){
                flag = 0 ;  //means Number is not Prime
                break ;
            }
        }
    }

    if(flag == 0 ){
        cout<<n<<" Is Not Prime.";
    }
    else{
        cout<<n<<" Is Prime.";
    }
}

int main(){
    int num ;

    cout<<"Enter The Number : ";
    cin>>num ;

    Prime(num);
    return 0 ;

}