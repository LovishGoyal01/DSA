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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        return pre(root,k,count);
    }
    int pre(TreeNode* root,int k,int& count){
        if(root==nullptr) return -1;
        int ans1 = pre(root->left,k,count);
        if(ans1!=-1) return ans1;

        count++;
        if(count==k) return root->val;

        int ans2= pre(root->right,k,count);
        if(ans2!=-1) return ans2;
        return -1;

    }
};