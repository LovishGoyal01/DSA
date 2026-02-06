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
    bool findval(TreeNode* root,int valu,int required){
       while(root){
        if(root->val!=valu && root->val==required) return true;
        else if(root->val<required) root=root->right;
        else root=root->left;
       }
       return false;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
          TreeNode* node = st.top();
          st.pop();
          bool ans = findval(root,node->val,k-node->val);
          if(ans) return true;
          if(node->left) st.push(node->left);
          if(node->right) st.push(node->right); 
        }
        return false;
    }
};