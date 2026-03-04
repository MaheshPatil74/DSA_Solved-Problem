#include<iostream>
using namespace std;

int main(){
        string s = "code";
        int score = 0 ;
        int i = 0 ;

        while( i<s.length()-1 ){
            int second = s[i+1] ;
            int first = s[i] ;
            cout << "Comparing " << first << " and " << second << endl ;
            cout<< (second-first) << endl ;
            cout << "Score before: " << score << endl ;
            score += (second-first) ;
            cout << "Score After: " << score << endl ;
            i++ ;
        }
}