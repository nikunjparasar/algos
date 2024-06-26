#include "include.h"
using namespace std;

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        return check(root, subRoot) || isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }

    bool check(TreeNode* t1, TreeNode* t2){
        if(!t1 || !t2) return !t1 && !t2;
        return t1->val == t2->val && check(t1->left, t2->left) && check(t1->right, t2->right);
    }
};