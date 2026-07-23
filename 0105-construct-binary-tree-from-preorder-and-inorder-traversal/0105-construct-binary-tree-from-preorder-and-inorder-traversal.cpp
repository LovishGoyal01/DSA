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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,0,n-1,inorder,0,n-1,mp);
    }
    
    TreeNode* build(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& mp){
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* node = new TreeNode(preorder[prestart]);
        int inroot = mp[node->val];
        int numsonLeft = inroot-instart;

        node->left = build(preorder,prestart+1,prestart+numsonLeft,
                           inorder,instart,inroot-1,mp);

        node->right = build(preorder,prestart+numsonLeft+1,preend,
                           inorder,inroot+1,inend,mp); 
        return node;                                     
    }
};