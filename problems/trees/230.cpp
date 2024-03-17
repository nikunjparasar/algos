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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        solve(root, k, v);
        if(v.size() >= k) return v[k-1];
        return 0;
    }

    void solve(TreeNode* root, int k, vector<int>& v){
        //inorder traversal
        if(root){
            solve(root->left, k, v);
            v.push_back(root->val);
            solve(root->right, k, v);
        }
    }
};