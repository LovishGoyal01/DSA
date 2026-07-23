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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        sum(root,maxi);
        return maxi;
    }
    int sum(TreeNode* root,int& maxi){
        if(root==nullptr) return 0;
        int l = max(0,sum(root->left,maxi));
        int r = max(0,sum(root->right,maxi));
        maxi = max(maxi,l + r + root->val);
        return max(l,r) + root->val;
    }
};