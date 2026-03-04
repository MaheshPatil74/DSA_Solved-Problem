#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    
    sort( arr.begin() , arr.end() ) ;

    vector<vector<int>> ans ;


    for( int i = 0 ; i<n-2 ; i++ ){

        if (i > 0 && arr[i] == arr[i - 1]) 
            continue;
        int p = i+1 ;
        int q = n-1 ;

        while( p<q ){
            int sum = arr[p] + arr[q] + arr[i] ;
            if( sum == K ){
                ans.push_back( {arr[i],arr[p],arr[q]} ) ;

                // Skip duplicates for p
                while (p < q && arr[p] == arr[p + 1]) 
                    p++;
                // Skip duplicates for q
                while (p < q && arr[q] == arr[q - 1]) 
                    q--;

                p++ ;
                q-- ;
            }
            else if( sum < K  ){
                p++ ;
            }   
            else{
                q-- ;
            }
        }
    }
        
    return ans ;
}