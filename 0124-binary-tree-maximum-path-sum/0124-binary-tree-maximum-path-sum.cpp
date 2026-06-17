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
    int sum(TreeNode* node,int& maxi){
        if(node==nullptr) return 0;
        int l=max(0,sum(node->left,maxi));
        int r=max(0,sum(node->right,maxi));
        maxi=max(node->val+l+r,maxi);
        return node->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxi=root->val;
        sum(root,maxi);
        return maxi;
    }
};