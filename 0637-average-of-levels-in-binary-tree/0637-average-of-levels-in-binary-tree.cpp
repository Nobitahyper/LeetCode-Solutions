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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (!root) return averages;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long tempSum = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                tempSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
                averages.push_back(static_cast<double>(tempSum) / size);
        }
        return averages;
    }
};