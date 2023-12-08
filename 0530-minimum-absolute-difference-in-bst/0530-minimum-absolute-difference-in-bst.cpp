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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inOrderTraverse(root, prev, minDiff);
        return minDiff;
    }

    void inOrderTraverse(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) return;

        inOrderTraverse(node->left, prev, minDiff);

        if (prev) {
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node;

        inOrderTraverse(node->right, prev, minDiff);
    }
};


