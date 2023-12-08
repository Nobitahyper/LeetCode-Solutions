/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> map;
        Node* current = head;

        while(current)
        {
            map[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while(current) {
            map[current]->next = map[current->next];
            map[current]->random = map[current->random];
            current = current->next;
        }
        return map[head];
    }
};