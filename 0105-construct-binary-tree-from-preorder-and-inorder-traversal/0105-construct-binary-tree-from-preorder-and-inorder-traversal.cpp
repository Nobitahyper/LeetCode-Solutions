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
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preOrder[preStart]);
        int inRoot = inStart;
        while (inOrder[inRoot] != root->val) {
            inRoot++;
        }

        int leftTreeSize = inRoot - inStart;

        root->left = build(preOrder, preStart + 1, preStart + leftTreeSize, inOrder, inStart, inRoot - 1);

        root->right = build(preOrder, preStart + leftTreeSize + 1, preEnd, inOrder, inRoot + 1, inEnd);

        return root;
    }
};

