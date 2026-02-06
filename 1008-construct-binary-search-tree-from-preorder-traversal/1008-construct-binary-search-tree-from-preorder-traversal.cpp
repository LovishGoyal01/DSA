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

    TreeNode* ans(vector<int>& preorder,int i,int j){
        if(i>j) return nullptr;
        int rightStart=j+1;
        for(int k=i+1;k<=j;k++){
            if(preorder[k]>preorder[i]){
                rightStart = k;
                break;
            }
        }
       TreeNode* node = new TreeNode(preorder[i]); 
       node->left =  ans(preorder,i+1,rightStart-1);
       node->right = ans(preorder,rightStart,j);
       return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return ans(preorder,0,preorder.size()-1);
    }
};