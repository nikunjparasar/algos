#include "include.h"
using namespace std;



//  * Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    // 10ms
    // O(nlogk) time
    // O(k) space
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(int i = 0; i < k; i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            if(top->next) pq.push(top->next);
            curr->next = top;
            curr = top;
            top->next = nullptr;
        }

        ListNode* res = head->next;
        delete head;
        return res;
    }
    struct comp{
        bool operator() (ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
    


    // 456 ms
    // n num nodes total
    // O(n*k) time
    // O(1) Space
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode* head = new ListNode(0);
    //     ListNode* curr = head;
    //     int k = lists.size();
    //     int nullct = 0;
    //     while(nullct != k){
    //         nullct = 0;
    //         int min = INT_MAX;
    //         int minIndex = -1;
    //         ListNode* minNode;
    //         for(int i = 0; i < k; i++){
    //             if(!lists[i]) nullct++;
    //             else{
    //                 ListNode* node = lists[i];
    //                 if(node->val < min){
    //                     min = node->val;
    //                     minIndex = i;
    //                     minNode = node;
    //                 }
    //             }
    //         }
    //         if(minIndex != -1){
    //             lists[minIndex] = minNode->next;
    //             curr->next = minNode;
    //             curr = minNode;
    //         }
    //     }

    //     ListNode* ans = head->next;
    //     delete head;
    //     return ans;
    // }
};