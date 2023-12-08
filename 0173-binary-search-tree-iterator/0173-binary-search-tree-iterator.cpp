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
class BSTIterator {
private:
    stack<TreeNode*> nodeStack;

    void pushLeftChildren(TreeNode* node) {
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }
    }
public:

    BSTIterator(TreeNode* root) {
        pushLeftChildren(root);
    }
    
    int next() {
        TreeNode* nextNode = nodeStack.top();
        nodeStack.pop();

        if (nextNode->right != nullptr) {
            pushLeftChildren(nextNode->right);
        }

        return nextNode->val;
    }
    
    bool hasNext() {
        return !nodeStack.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
