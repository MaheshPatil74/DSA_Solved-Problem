// Approach 3 (Single Temp Array Reused) : Most Optimal
// TC : O( N*LogN ) , SC : O(N) // recursion
class Solution {
private :
    void merge(vector<int>& nums, int*temp ,int s , int e ){
        int mid = s + (e-s)/2 ;

        int left = s ;
        int right = mid+1 ;
        int tempIdx = 0 ;

        while( left <= mid && right <= e ){
            if( nums[left] <= nums[right] )
                temp[tempIdx++] = nums[left++] ;
            else
                temp[tempIdx++] = nums[right++] ;
        }
        while( left <= mid )
            temp[tempIdx++] = nums[left++] ;
        while( right <= e )
            temp[tempIdx++] = nums[right++] ;

        for( int i = s ; i<=e ; i++ )
            nums[i] = temp[i-s] ;
    }
    void mergeSort(vector<int>& nums,int * temp,int s , int e ){
        if( s>=e )  return ;

        int mid = s + (e-s)/2 ;
        mergeSort(nums ,temp, s , mid);
        mergeSort(nums,temp, mid+1 , e );
        merge( nums,temp,s,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int* temp  = new int[nums.size()] ;
        mergeSort(nums,temp,0,nums.size()-1) ;
        return nums ; 
    }
};

// Approach 2 (Temp Vector Each Merge Call)
// TC : O( N*LogN ) , SC : O(N) // recursion
class Solution {
private :
    void merge(vector<int>& nums,int s , int e ){
        int mid = s + (e-s)/2 ;
        int* temp  = new int[nums.size()] ;

        int left = s ;
        int right = mid+1 ;
        int tempIdx = 0 ;

        while( left <= mid && right <= e ){
            if( nums[left] <= nums[right] )
                temp[tempIdx++] = nums[left++] ;
            else
                temp[tempIdx++] = nums[right++] ;
        }
        while( left <= mid )
            temp[tempIdx++] = nums[left++] ;
        while( right <= e )
            temp[tempIdx++] = nums[right++] ;

        for( int i = s ; i<=e ; i++ )
            nums[i] = temp[i-s] ;
        delete []temp;
    }
    void mergeSort(vector<int>& nums,int s , int e ){
        if( s>=e )  return ;

        int mid = s + (e-s)/2 ;
        mergeSort(nums , s , mid);
        mergeSort(nums, mid+1 , e );
        merge( nums,s,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1) ;
        return nums ; 
    }
};


// Approach 1 (Two Dynamic Arrays Using new/delete)
// TC : O( N*LogN ) , SC : O(N) // recursion
class Solution {
private :
    void merge(vector<int>&nums,int s , int e ){
        int mid = s + (e-s)/2 ;
        int len1 = mid-s+1 ;
        int len2 = e-mid ;

        int* first = new int[len1] ;
        int* second = new int[len2] ;

        // copy value
        int mainIndex = s ;
        for( int i = 0 ; i<len1 ; i++ )
            first[i] = nums[mainIndex++] ;

        mainIndex = mid+1 ;
        for( int i = 0 ; i<len2 ; i++ )
            second[i] = nums[mainIndex++] ;

        int idx1 = 0 ;
        int idx2 = 0 ;
        mainIndex = s ;

        while( idx1<len1 && idx2<len2 ){
            if( first[idx1] < second[idx2] )
                nums[mainIndex++] = first[idx1++];
            else
                nums[mainIndex++] = second[idx2++] ;
        }
        while( idx1<len1 )
            nums[mainIndex++] = first[idx1++];

        while( idx2<len2 )
            nums[mainIndex++] = second[idx2++] ;

        delete []first ;
        delete []second ;
    }

    void mergeSort(vector<int>&nums , int s , int e ){
        if( s>=e )
            return ;

        int mid = s + (e-s)/2 ;
        mergeSort(nums,s,mid) ;
        mergeSort(nums,mid+1,e) ;
        merge(nums,s,e) ;
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size()-1) ;
        return nums ;
    }
};