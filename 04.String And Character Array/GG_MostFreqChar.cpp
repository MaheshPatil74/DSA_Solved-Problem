#include<iostream>
using namespace std ;

char getMostOccChar(string s){
    int arr[26] = { 0 } ;

    //create array of count of character
    for(int i = 0 ; i<s.length() ; i++ ){
        char ch = s[i] ;
        //lowercase
        int number = 0 ;
        if(ch>='a' && ch<='z'){
            number = ch - 'a' ;
        }
        else{
            //Uppercase
            number = ch - 'A' ;
        }
        arr[number]++ ;
    }

    int maxi = -1 , ans = 0 ;
    for(int i = 0 ; i<26 ; i++ ){
        if( maxi<arr[i] ){
            ans = i ;
            maxi = arr[i] ;
        }
    }
    char finalAns = 'a' + ans ;
    return finalAns ;
}

int main(){
    string s ;
    cout<<"Enter String : ";
    cin>>s ;

    cout<<"Most Frequest Occuring Character : "<<getMostOccChar(s)<<endl ;
}