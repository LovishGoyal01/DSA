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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return create(preorder,i,INT_MAX);
    }
    TreeNode* create(vector<int>& preorder,int& i,int ub)
    {   
        if(i==preorder.size() || preorder[i]>ub) return nullptr;
        TreeNode* temp = new TreeNode(preorder[i++]);
        temp->left = create(preorder,i,temp->val);
         temp->right = create(preorder,i,ub);
         return temp;
    }
};