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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next; // skip duplicates
            }
            if (prev->next == curr) {
                prev = prev->next; // no duplicates found, move prev
            } else {
                prev->next = curr->next; // skip all duplicates
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};

