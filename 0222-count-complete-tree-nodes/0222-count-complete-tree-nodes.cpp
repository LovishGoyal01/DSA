/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findLeftH(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+findLeftH(root->left);
    }
    int findrightH(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+findrightH(root->right);
    }
    int countNodes(TreeNode* root) {
         if(root==nullptr) return 0;
         int lh = findLeftH(root);
         int rh = findrightH(root);
         if(lh==rh) return (1<<lh)-1;
          return 1 + countNodes(root->left) + countNodes(root->right);
    }
};