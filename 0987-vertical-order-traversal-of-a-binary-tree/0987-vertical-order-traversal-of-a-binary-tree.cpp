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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo; //{Node,x,level}
        vector<vector<int>>ans;
        if(!root) return ans;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto it = todo.front();
            todo.pop();
            TreeNode* temp = it.first;
            int x=it.second.first;
            int y=it.second.second;
            nodes[x][y].insert(temp->val);
            if(temp->left) todo.push({temp->left,{x-1,y+1}});
            if(temp->right) todo.push({temp->right,{x+1,y+1}});
        }
        for(auto p:nodes){
           vector<int>cols;
           for(auto q:p.second){
             cols.insert(cols.end(),q.second.begin(),q.second.end());
           }
           ans.push_back(cols);
        }
      return ans;
    }
};