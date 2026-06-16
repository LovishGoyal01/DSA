class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        if (root == nullptr)
            return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            preorder.push_back(node->val);

            if (node->right)
                st.push(node->right);

            if (node->left)
                st.push(node->left);
        }

        return preorder;
    }
};