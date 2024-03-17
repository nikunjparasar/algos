#include "include.h"
using namespace std;


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // //recursive solution
    // ListNode* reverseList(ListNode* head){
    //     if(head == nullptr || head->next == nullptr) return head;
    //     ListNode* newHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return newHead;
    // }
};