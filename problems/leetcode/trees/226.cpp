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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        if(root->left && root->right){
            TreeNode* temp = root->right;
            root->right = invertTree(root->left);
            root->left = invertTree(temp);
        } 
        else if(root->left && !root->right){
            root->right = invertTree(root->left);
            root->left = nullptr;
        }
        else if(root->right && !root->left){
            root->left = invertTree(root->right);
            root->right = nullptr;
        }
        return root;
    }
};