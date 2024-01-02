#include "include.h"
using namespace std;


class LRUCache {
private:
    list<pair<int, int>> ll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        ll.splice(ll.begin(), ll, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            cache[key]->second = value;
            ll.splice(ll.begin(), ll, cache[key]);
        }
        else{
            if(cache.size() == cap){
                cache.erase(ll.back().first);
                ll.pop_back();
            }
            ll.push_front({key, value});
            cache[key] = ll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */







// class LRUCache {
// private:
//     // doubly linked list:  lru <-> ... <-> ... <-> mru
//     struct Node {
//         int key, val;
//         Node *prev, *next;
//         Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
//     };
//     Node* lru; 
//     Node* mru;

//     void useNode(Node* node){
//         if(node == mru->prev) return;
//         // detach the node
//         if(node->next) node->next->prev = node->prev;
//         if(node->prev) node->prev->next = node->next;

//         // add node the mru spot
//         mru->prev->next = node;
//         node->prev = mru->prev;
//         node->next = mru;
//         mru->prev = node;
//     }

//     void clearLRU(){
//         Node* node = lru->next;
//         if(node == mru) return;
//         cache.erase(node->key);
//         Node* next = node->next;
//         next->prev = node->prev;
//         delete node;
//         lru->next = next;
//     }

//     unordered_map<int, Node*> cache;
//     int cap;

// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         lru = new Node(-1, -1);
//         mru = new Node(-1, -1);

//         lru->next = mru;
//         mru->prev = lru;
//     }
    
//     ~LRUCache(){
//         while(lru){
//             Node* next = lru->next;
//             delete lru;
//             lru = next;
//         }
//     }

//     int get(int key) {
//         if(cache.find(key) == cache.end()) return -1;
//         else{
//             useNode(cache[key]);
//             return cache[key]->val;
//         }
//     }
    
//     void put(int key, int value) {
//         if(cache.find(key) != cache.end()){
//             cache[key]->val = value;
//         }
//         else{
//             if(cache.size() < cap){
//                 cache[key] = new Node(key, value);
//             }
//             else{
//                 clearLRU();
//                 cache[key] = new Node(key, value);
//             }
//         }
//         useNode(cache[key]);

//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */