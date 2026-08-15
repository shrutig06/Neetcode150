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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int total=0;
        while(curr!=nullptr){
            curr=curr->next;
            total++;
        }
        // nth node from end, if n is 5 and total nodes are 5 we need to remove head node
        if(total==n) return head->next;
        curr=head;
        int pos=1;
        ListNode* prev;
        while(curr && pos<=total-n){
            prev=curr;
            pos++;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};