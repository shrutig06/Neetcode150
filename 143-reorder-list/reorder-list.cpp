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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = slow->next;
        slow->next = nullptr;

        ListNode* curr = secondHead;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while (first && second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            first->next = second;
            second->next = firstNext;
            first = firstNext;
            second = secondNext;
        }
    }
};