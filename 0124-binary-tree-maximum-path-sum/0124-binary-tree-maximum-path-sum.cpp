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
    int maxSum = INT_MIN;

    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftMax = max(dfs(node->left), 0);

        int rightMax = max(dfs(node->right), 0);

        maxSum = max(maxSum, node->val + leftMax + rightMax);

        return node->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};