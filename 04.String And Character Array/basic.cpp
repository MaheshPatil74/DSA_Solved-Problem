#include<iostream>
using namespace std ;

void PrintArray(char arr[]){
    for(int i=0 ; arr[i]!='\0' ; i++ ){
        cout<<arr[i];
    }
    cout<<endl ;
}

    char toLower(char ch){
        if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9') ){
            return ch ;
        }
        else{
            char temp = ch - 'A' + 'a' ;
            return temp ;
        }
    }

char toUpper(char ch){
    if( (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') ){
        return ch ;
    }
    else{
        char temp = ch - 'a' + 'A   ' ;
        return temp ;
    }
}


int getLength( char arr[] ){
    int count = 0 ;
    for(int i = 0 ; arr[i]!='\0' ; i++ ){
        count++ ;
    }
    return count ;
}

void Reverse1( char arr[] ){
    int n = getLength(arr) ;

    for(int i=0 ; i<n/2 ; i++ ){
        swap(arr[i],arr[n-i-1]);
    }
}

//Two Pointer Approach for Reverse Of String
void Reverse2(char arr[] , int n ){
    int s = 0 ;
    int e = n-1 ;

    while(s<e){
        swap(arr[s++] , arr[e--] );
    }

}

int main(){

    char name[20] ;

    cout<<"Enter Your Name : ";
    cin>>name ;

    cout<<"Your Name : "<<name<<endl ;;

    int len = getLength(name) ;
    cout<<"Length Of Character Array : "<<len<<endl ;
    
    cout<<"Initial Array : ";
    PrintArray(name) ;
    
    // Reverse1(name) ;
    Reverse2(name,len) ;
    
    cout<<"Reverse Array : ";
    PrintArray(name) ;

    return 0 ;
}