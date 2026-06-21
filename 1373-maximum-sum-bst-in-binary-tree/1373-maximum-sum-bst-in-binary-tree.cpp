/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Info {
public:
    int mn, mx, sum;

    Info(int mn, int mx, int sum) {
        this->mn = mn;
        this->mx = mx;
        this->sum = sum;
    }
};

class Solution {
    int ans = 0;

    Info solve(TreeNode* root) {
        if (!root)
            return Info(INT_MAX, INT_MIN, 0);

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Current subtree is BST
        if (left.mx < root->val && root->val < right.mn) {
            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return Info(
                min(left.mn, root->val),
                max(right.mx, root->val),
                currSum
            );
        }

        // Invalid BST
        return Info(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};