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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* start = new ListNode(0);
        ListNode* tail = start;
        while(l1 || l2 || carry){
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            ListNode* node = new ListNode(digit);
            tail->next = node;
            tail = node;
            carry = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

        }
        ListNode* ans = start->next;
        delete start;
        return ans;
    }
    


};