#include <iostream>
#include <math.h>
using namespace std;

// Problem: Decimal To Binary
int DecimalToBinary1(int n) {
    int ans = 0 ;
    int place = 1 ;
    while( n!= 0 ){
        int digit = n%2 ;
        ans = ( digit * place ) + ans ;
        place *= 10 ;
        n = n / 2 ;
    }
    return ans;
}

int DecimalToBinary2(int n) {
    int ans = 0 ;
    int place = 1 ;
    while( n!= 0 ){
        int bit = n&1 ;
        ans = (bit * place) + ans ;
        place *= 10 ;
        n = n>>1 ;
    }
    return ans ;
}

int main() {
    int num;
    cout << "Enter The Number: ";
    cin >> num;

    cout << "Answer: " << DecimalToBinary1(num)<<endl;
    cout << "Answer: " << DecimalToBinary2(num)<<endl;
    return 0;
}