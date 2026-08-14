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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* before=nullptr, *after=nullptr, *first=nullptr;
        int pos = 1;
        ListNode* curr = head;

        while (curr) {
            if (pos == left - 1)
                before = curr;
            else if (pos == left)
                first = curr;
            else if (pos == right + 1)
                after = curr;
            curr = curr->next;
            pos++;
        }

        ListNode* prev, *nextNode;
        prev=after;
        curr=first;
        while(curr && curr!=after){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        if(before) {
            before->next=prev;
        } else{
            return prev;
        }

        return head;
    }
};