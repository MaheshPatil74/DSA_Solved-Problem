#include<iostream>
using namespace std ;

class TrieNode{
    public :
        char data ;
        TrieNode* children[26] ;
        bool isTerminal ;

        TrieNode( char data ){
            this->data = data ;
            for(int i = 0 ; i<26 ; i++ ){
                children[i] = NULL ;
            }
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
        int index = word[0] - 'A' ;
        TrieNode* child ;

        // child present
        if( root->children[index] != NULL ){
            child = root->children[index] ;
        }
        else{
            // child absent
            child = new TrieNode(word[0]) ;
            root->children[index] = child ;
        }

        // recursion
        insertUtil( child , word.substr(1) );
    }

    // TC =O(length of word)
    void insertWord( string word ){
        insertUtil( root , word ) ;
    }

    bool searchUtil(TrieNode* root , string word ){
        //base case
        if(word.length() == 0 ){
            return root->isTerminal ;
        }

        // Assume word will be in caps
        int index = word[0] - 'A' ;
        TrieNode* child ;

        // child present
        if( root->children[index] != NULL ){
            child = root->children[index] ;
        }
        else{
            // absent
            return false ;
        }

        // recursion
        return searchUtil( child , word.substr(1) );
    }

    // TC =O(length of word)
    bool searchWord( string word ){
        return searchUtil(root,word) ;
    }

    void removeUtil(TrieNode* root , string word ){
        //base case
        if(word.length() == 0 ){
            root->isTerminal = false ;
            return ;
        }

        // Assume word will be in caps
        int index = word[0] - 'A' ;
        TrieNode* child ;

        // child present
        if( root->children[index] != NULL ){
            child = root->children[index] ;
        }
        else{
            // absent
            return ;
        }

        // recursion
        removeUtil( child , word.substr(1) );
    }

    // the below removeWord function is good for small cases but its can't deallocate memmory
    // so deallocation code are at end of this code give ny chatgpt
    // TC =O(length of word)
    void removeWord( string word ){
        removeUtil(root , word ) ;
    }
};

int main(){

    trie* t = new trie() ;
    t->insertWord("ARM") ;
    t->insertWord("DO") ;
    t->insertWord("TIME") ;
    

    cout<<"Present or Not : "<< t->searchWord("TIME")<<endl ;
    t->removeWord("TIME") ;
    cout<<"Present or Not : "<< t->searchWord("TIME")<<endl ;
    // cout<<"Present or Not : "<< t->searchWord("TIM")<<endl ;

    return 0 ;
}

/*

// This Code is given by CHATGPT
#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // Updated: remove and deallocate nodes when they're no longer needed
    bool removeUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;

                // If all children are NULL, this node can be deleted
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL)
                        return false; // can't delete this node
                }

                return true; // safe to delete this node
            }
            return false;
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL)
            return false;

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;

            // Check if current root has any other children or is terminal
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL)
                        return false;
                }
                return true;
            }
        }

        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }

    ~Trie() {
        delete root;
    }
};
*/