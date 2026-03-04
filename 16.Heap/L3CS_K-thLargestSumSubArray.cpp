#include<algorithm>

// Approach 1 ==>> 
// TC = (N*N).log(N) 
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int> sumStore ;
	int n = arr.size() ;

    // TC = O(N*N)
	for(int i = 0 ; i<n ; i++ ){
		int sum = 0 ;
		for(int j = i ; j<n ; j++ ){
			sum += arr[j] ;
			sumStore.push_back(sum) ;
		}
	}

    // TC = (N*N).log(N) 
	sort(sumStore.begin(),sumStore.end()) ;
	int size = sumStore.size() ;
	
	return sumStore[size-k] ;
}

// Approach 2 ==>> 
// TC = (N*N).log(k)  and SC = O(k)

#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int , vector<int> , greater<int> > mini ;

	int n = arr.size() ;
	for(int i = 0 ; i<n ; i++ ){
		int sum = 0 ;
		for(int j = i ; j<n ; j++ ){
			sum += arr[j] ;
			if( mini.size() < k ){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){
					mini.pop() ;
					mini.push(sum);
				}
			}
		}
	} 
	return mini.top() ;
}