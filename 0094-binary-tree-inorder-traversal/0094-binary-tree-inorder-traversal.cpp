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
    void traverse(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return;
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
        traverse(root,ans);
        return ans;   
    }

    // vector<int> inorderTraversal(TreeNode* root) {
    //         vector<int> inorder;
    //     TreeNode* cur = root;

    //     while (cur != NULL) {

    //         // Case 1: No left child
    //         if (cur->left == NULL) {
    //             inorder.push_back(cur->val);
    //             cur = cur->right;
    //         }
    //         // Case 2: Left child exists
    //         else {
    //             TreeNode* prev = cur->left;

    //             // Find inorder predecessor
    //             while (prev->right != NULL && prev->right != cur) {
    //                 prev = prev->right;
    //             }

    //             // Create thread
    //             if (prev->right == NULL) {
    //                 prev->right = cur;
    //                 cur = cur->left;
    //             }
    //             // Remove thread
    //             else {
    //                 prev->right = NULL;
    //                 inorder.push_back(cur->val);
    //                 cur = cur->right;
    //             }
    //         }
    //     }
    //     return inorder;
    // }
};