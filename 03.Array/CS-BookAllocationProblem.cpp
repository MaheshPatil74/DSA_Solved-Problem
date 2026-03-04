#include <iostream>
using namespace std ;

// Answer of nowasdays Question
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, vector<int> &time, long long mid) {

    int dayCount = 1;
    long long timeSum = 0;

    for (int i = 0; i < time.size(); i++) {
        if (timeSum + time[i] <= mid) {
            timeSum += time[i];
        } else {
            dayCount++;
            if (dayCount > n || time[i] > mid)
                return false;
            timeSum = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {

    long long start = *max_element(time.begin(), time.end());
    long long end = 0;
    for (int t : time) end += t;

    long long ans = -1;

    while (start <= end) {
        long long mid = start + (end - start) / 2;

        if (isPossible(n, time, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}




// Sir Code at that Time Question is another
bool isPossible(int arr[] , int n , int m , int mid ){
    int studentCount = 1 ;
    int pageSum = 0 ;
    for(int i = 0 ; i<n ; i++){
        if( pageSum + arr[i] <= mid ){
            pageSum += arr[i] ;
        }else{
            studentCount++ ;
            if( studentCount > m || arr[i]>mid ){
                return false ;
            }
            pageSum = arr[i] ;
        }
    }
    return true ;
}

int allocateBook( int arr[] , int n , int m ){
    int s = 0 ;
    int sum = 0 ;
    for( int i = 0 ; i<n ; i++ ){
        sum += arr[i] ;
    }
    int e = sum ;
    int ans = -1 ;
    int mid = s + (e-s)/2 ;
    
    while(s<=e){
        if( isPossible( arr , n , m , mid ) ){
            ans = mid ;
            e = mid - 1 ;
        }else{
            s = mid + 1 ;
        }
        mid = s + (e-s)/2 ;
    }
    return ans ;
}

int main() {
    
    int array[4] = { 10 , 20 , 30 , 40 } ;
    
    int StudentNumber = 2 ;
    int BooksNumber = 4 ;
    
    cout<<allocateBook(array , BooksNumber , StudentNumber );
    return 0;
}