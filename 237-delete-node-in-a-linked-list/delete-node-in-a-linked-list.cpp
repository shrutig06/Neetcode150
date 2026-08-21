/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Approach => When I cannot modify the previous node, can I modify the current node to absorb the next node and then bypass the next node?
        ListNode* del=node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete(del);
    }
};