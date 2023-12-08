/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        int length = 1;
        ListNode* curr = head;
        while (curr->next) {
            length++;
            curr = curr->next;
        }
        curr->next = head;

        k %= length;
        for (int i = 0; i < length - k - 1; i++) {
            head = head->next;
        }
        curr = head->next;
        head->next = nullptr;
        head = curr;
        
        return head;
    }
};

