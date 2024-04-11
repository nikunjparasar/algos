#include "include.h"
class Trie {
public:
    struct Node{
        Node* children[26];
        char value;
        bool end_word;
        Node(char val): value(val), end_word(false) {
            memset(children, 0x0, sizeof(children));
        }
    
    };

    Node* root;
    Trie() {
        root = new Node('-');
    }

    
    void insert(string word) {
        int n = word.size();
        Node* ptr = root;
        for(int i = 0; i < n; ++i){
            if(ptr->children[word[i]-'a']) ptr = ptr->children[word[i]-'a'];
            
            else {
                Node * node = new Node(word[i]);
                ptr->children[word[i]-'a'] = node;
                ptr = node;
            }
            
            if(i == n-1) ptr->end_word = true;
        }
    }
    
    bool search(string word) {
        int n = word.size();
        Node* ptr = root;
        for(int i = 0; i < n; ++i){
            if(ptr->children[word[i]-'a']) {
                ptr = ptr->children[word[i]-'a'];
            } else {
                return false;
            }
        }
        return ptr->end_word;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* ptr = root;
        for(int i = 0; i < n; ++i){
            if(ptr->children[prefix[i]-'a']) ptr = ptr->children[prefix[i]-'a'];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
