
// Approach 1 :
// TC = O( M*N ) and SC = O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";

    if( arr.size() == 0 ){
            return ans ;
    }

    // for traversing all character of first string
    for( int i = 0 ; i<arr[0].length() ; i++ ){

        char ch = arr[0][i] ;
        bool match = true ;

        // for comparing "ch" with rest of the string
        for( int j = 1 ; j<n ; j++ ){
            // not match
            if( arr[j].size() < i || ch != arr[j][i] ){
                match = false ;
                break ;
            }
        }

        if( match == false )
            break ;
        else
            ans.push_back(ch) ;
    }
    return ans ;
}



// Approach 2 :
// TC = O( M*N ) and SC = O(M*N)
class TrieNode{
    public :
        char data ;
        TrieNode* children[26] ;
        bool isTerminal ;
        int childCount ;

        TrieNode( char data ){
            this->data = data ;
            for(int i = 0 ; i<26 ; i++ ){
                children[i] = NULL ;
            }
            childCount = 0 ;
            isTerminal = false ;
        }
};

class trie{
  public :
    TrieNode* root  ;
    
    trie(){
        root = new TrieNode('\0') ;
    }

    void insertUtil(TrieNode* root , string word){
        //base case
        if(word.length() == 0 ){
            root->isTerminal = true ;
            return ;
        }

        // Assume word will be in caps
        int index = word[0] - 'a' ;
        TrieNode* child ;

        // child present
        if( root->children[index] != NULL ){
            child = root->children[index] ;
        }
        else{
            // child absent
            child = new TrieNode(word[0]) ;
            root->childCount++ ;
            root->children[index] = child ;
        }

        // recursion
        insertUtil( child , word.substr(1) );
    }

    // TC =O(length of word)
    void insertWord( string word ){
        insertUtil( root , word ) ;
    }

    // void lcp(string str , string& ans ){

    //     for(int i = 0 ; i<str.length() ; i++ ){
    //         char ch = str[i] ;

    //         if( root->childCount == 1 ){
    //             ans.push_back(ch) ;

    //             // aage badho
    //             int index = ch - 'a' ;
    //             root = root->children[index] ;

    //         }
    //         else{
    //             break ;
    //         }

    //         if( root->isTerminal ){
    //             break ;
    //         }
    //     }
    // }

    void lcp(string str, string& ans) {
        TrieNode* temp = root;

        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (temp->childCount == 1 && !temp->isTerminal) {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            }
            else {
                break;
            }
    }
}

};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    trie* t = new trie() ;

    // insert all string into trie
    for(int i = 0 ; i<n ; i++ )
        t->insertWord(arr[i]) ;

    string first = arr[0] ;
    string ans = "" ;

    t->lcp(first , ans );

    return ans ; 
}