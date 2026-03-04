#include<iostream>
using namespace std ;

// MaxHeap Implementation==>>
// Using Array and one base indexing

class maxHeap{
    private :
        int arr[100] ;
        int size ;

    public :
        maxHeap(){
            arr[0] = -1 ;
            size = 0 ;
        }

        // TC = O(logN)
        void insert(int val){
            size++ ;
            int index = size ;
            arr[index] = val ;

            while( index>1 ){
                int parent = index/2 ;

                if( arr[index] > arr[parent]){
                    swap(arr[index],arr[parent])  ;
                    index = parent ;
                }
                else{
                    return ;
                }
            }
        }

        // In deletion we always delete root node
        // TC = O(logN)
        void deleteFromHeap(){
            if(size==0){
                cout<<"Nothing to delete==>> Heap is Empty!!"<<endl;
                return ;
            }

            // S1) put last element into first index
            arr[1] = arr[size] ;
            // s2) remove last element
            size-- ;

            // step3) take root node to its correct position
            int i = 1 ;
            while(i<size){
                int leftIndex = 2*i ;
                int rightIndex = 2*i + 1 ;

                if( leftIndex<size && arr[i]<arr[leftIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i = leftIndex ;
                }
                else if( rightIndex<size && arr[i]<arr[rightIndex]){
                    swap(arr[i],arr[rightIndex]);
                    i = rightIndex ;
                }
                else{
                    return ;
                }
            }
        }

        void print(){
            cout<<"Printing Heap Array : ";
            for(int i = 1 ; i<=size ; i++)
                cout<< arr[i] << " ";
            cout<<endl ;
        }
};

int main(){
    maxHeap h ;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print() ;
    h.deleteFromHeap() ;
    h.print() ;

    return 0 ;
}