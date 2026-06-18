/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track)
     {
        if(root==nullptr) return;
        if(root->left){
            parent_track[root->left]=root;
            markParents(root->left,parent_track);
        }
        if(root->right){
            parent_track[root->right]=root;
            markParents(root->right,parent_track);
        }  
     }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParents(root,parent_track);

        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        int curr=0;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int size = q.size();
            if(curr++==k) break;
            for(int i=0;i<size;i++){
              TreeNode* node = q.front();
              q.pop();
              if(node->left && !visited[node->left]){
                 q.push(node->left);
                 visited[node->left]=true;
              }
              if(node->right && !visited[node->right]){
                 q.push(node->right);
                 visited[node->right]=true;
              }
              if(parent_track[node] && !visited[parent_track[node]]){
                 q.push(parent_track[node]);
                 visited[parent_track[node]]=true;
              }
            }  
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};