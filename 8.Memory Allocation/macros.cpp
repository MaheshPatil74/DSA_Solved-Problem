#include<iostream>
using namespace std ;

#define PI 3.14     //These Macros Can not used any memory of System  
// helpful as before compilation PI is replace by their value that is 3.14

int main(){

    int r = 5 ;
    //double PI = 3.14  //these uses a 8 bit memory 
    //hence we used Macros 

    double area = PI * r * r ;
    cout<<"Area : "<<area<<endl ;

    return 0 ;
}