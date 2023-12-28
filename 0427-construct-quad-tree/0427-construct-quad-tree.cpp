/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructQuadTree(grid, 0, 0, grid.size());
    }
private:
    Node* constructQuadTree(const vector<vector<int>>& grid, int x, int y, int length) {
        if (length == 1) {
            return new Node(grid[x][y] != 0, true, nullptr, nullptr, nullptr, nullptr);
        }
        int newLength = length / 2;
        
        Node* topLeft = constructQuadTree(grid, x, y, newLength);
        Node* topRight = constructQuadTree(grid, x, y + newLength, newLength);
        Node* bottomLeft = constructQuadTree(grid, x + newLength, y, newLength);
        Node* bottomRight = constructQuadTree(grid, x + newLength, y + newLength, newLength);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
            bool val = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};


