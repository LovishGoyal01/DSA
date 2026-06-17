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
    int cal(TreeNode* node,int& dia){
      if(node==nullptr) return 0;
      int l=cal(node->left,dia);
      int r=cal(node->right,dia);
      dia= max(dia,l+r);
      return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        cal(root,dia);
        return dia;   
    }
};