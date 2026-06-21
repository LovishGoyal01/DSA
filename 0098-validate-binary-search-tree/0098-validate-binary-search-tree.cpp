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
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MAX,LONG_MIN);
    }

    bool isValid(TreeNode* root,long maxR,long minR) {
        if(root==nullptr) return true;
        if(root->val<=minR || root->val>=maxR) return false;
        return isValid(root->left,root->val,minR) 
              && isValid(root->right,maxR,root->val);
    }
};