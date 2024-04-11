#include "include.h"
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        //count the number of nodes in the list
        int t = 0;
        ListNode* c = head;
        while(c != nullptr){
            c = c->next;
            t++;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        int i = 0;
        while(curr !=  nullptr){
            i++;
            if(t-i+1 == n){
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if(prev == nullptr) return head->next;
        prev->next = curr->next;
        return head;
    }
};