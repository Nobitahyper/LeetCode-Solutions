/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
        Node* connect(Node* root) {
        if (!root) return nullptr;

        // Initialize a queue for level order traversal
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;

            // Iterate over all nodes at the current level
            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                // Connect the previous node (if it exists) to the current node
                if (prev) {
                    prev->next = current;
                }
                prev = current;

                // Enqueue children of the current node
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            // After the last node of each level, set next to nullptr
            if (prev) {
                prev->next = nullptr;
            }
        }

        return root;
    }
};

