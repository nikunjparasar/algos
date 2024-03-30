#include "include.h"

truct node{
    int key;
    node* next;
    node* prev;
    node(int key): key(key), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, int> cache;
    unordered_map<int, node*> key_node;
    node* lru;
    node* mru;

    void useKey(int key){
        node* n;
        if(key_node.find(key) == key_node.end())  n = new node(key);
        else{
            n = key_node[key];
            n->prev->next = n->next;
            n->next->prev = n->prev;
        } 
        key_node[key] = n;
        node* temp = mru->prev;
        temp->next = n;
        n->prev = temp;
        mru->prev = n;
        n->next = mru;
    }

    void removeLRU(){
        node* n = lru->next;
        if(n == mru) return;
        cache.erase(n->key);
        key_node.erase(n->key);
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
    }

public:
    LRUCache(int capacity) : cap(capacity){
        lru = new node(-1);
        mru = new node(-1);
        mru->prev = lru;
        lru->next = mru;
    }

    ~LRUCache(){
        node* ptr = lru;
        while(ptr){
            node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        useKey(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.size() >= cap && cache.find(key) == cache.end()) removeLRU();
        cache[key] = value;
        useKey(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */