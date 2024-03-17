#include "include.h"
using namespace std;


class MyHashMap {
private:
    static const int SIZE = 1000;
    struct Node {
        int key;
        int val;
        Node* next;
        Node(int k, int v) : key(k), val(v), next(nullptr) {}
    };
    vector<Node*> map;

public:
    MyHashMap() {
        map.resize(SIZE, nullptr);
    }

    void put(int key, int value) {
        int index = key % SIZE;
        if (map[index] == nullptr) {
            map[index] = new Node(key, value);
        } else {
            Node* current = map[index];
            while (current->next != nullptr && current->key != key) {
                current = current->next;
            }
            if (current->key == key) {
                current->val = value;  // Update value if key exists
            } else {
                current->next = new Node(key, value);
            }
        }
    }

    int get(int key) {
        int index = key % SIZE;
        Node* current = map[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->val;  // Return the value if key exists
            }
            current = current->next;
        }
        return -1;  // Key not found
    }

    void remove(int key) {
        int index = key % SIZE;
        Node* current = map[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev != nullptr) {
                    prev->next = current->next;
                } else {
                    map[index] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};