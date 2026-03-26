// TC : O(M+N) , SC : o(1)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if( typed.size() < name.size() )
            return false ;
        
        int nameIdx = 0 ;
        int typedIdx = 0 ;
        while( typedIdx < typed.size() ){
            if( typed[ typedIdx ] == name[nameIdx] ){
                nameIdx++ ;
                typedIdx++ ;
            }
            else if( typedIdx>0 && typed[typedIdx] == typed[typedIdx-1] )
                typedIdx++ ;
            else
                return false ;
        }
        return nameIdx == name.size() ;      
    }
};