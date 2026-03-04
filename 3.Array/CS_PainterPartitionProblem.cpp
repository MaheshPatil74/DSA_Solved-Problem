bool isPossible(vector<int> &boards, int k, int mid ){
    int painterCount = 1 ;
    int lengthSum = 0 ;

    for( int i =0 ; i < boards.size() ; i++ ){
        if( lengthSum + boards[i] <= mid )
            lengthSum += boards[i] ;
        else{
            painterCount++ ;
            if( painterCount>k || boards[i]>mid ){
                return false ;
            }
            lengthSum = boards[i] ;
        }
    }
    return true ;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int left = 0 ;
    int sum = 0 ;
    for( int i = 0 ; i<boards.size() ; i++ ){
        sum += boards[i] ;
    }
    int right = sum ;
    int ans = -1 ;

    while( left <= right ){
        int mid = left + (right-left)/2 ;

        if( isPossible (boards , k , mid ) ){
            ans = mid ;
            right = mid-1 ;
        }
        else{
            left = mid+1 ;
        }
    }
    return ans ;
}