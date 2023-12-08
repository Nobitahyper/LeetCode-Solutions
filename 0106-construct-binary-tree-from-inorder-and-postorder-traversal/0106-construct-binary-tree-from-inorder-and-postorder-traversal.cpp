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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    }

    TreeNode* build(vector<int>& inOrder, int inStart, int inEnd, vector<int>& postOrder, int postStart, int postEnd, unordered_map<int, int>& inMap)
    {
        if (postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postOrder[postEnd]);

        int inRoot = inMap[root->val];
        int leftTreeSize = inRoot - inStart;

        root->left = build(inOrder, inStart, inRoot - 1, postOrder, postStart, postStart + leftTreeSize - 1, inMap);

        root->right = build(inOrder, inRoot + 1, inEnd, postOrder, postStart + leftTreeSize, postEnd - 1, inMap);

        return root;
    }
};

