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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = 0,  rightHeight = 0;
        TreeNode *left = root, *right = root;

        while (left) { leftHeight++; left = left->left; }
        while (right) { rightHeight++; right = right->right; }

        // if the height are same then it's a perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; // 2^height - 1
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

