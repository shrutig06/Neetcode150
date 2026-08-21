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
        // ListNode* dummy=new ListNode(0);
        // dummy->next=head;
        ListNode* curr=head;
        int cnt=0;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        if(n==cnt) return head->next;
        int pos=1;
        curr=head;
        while(pos<cnt-n){
            pos++;
            curr=curr->next;
        }
        // cout<<curr->val<<" ";
        if(curr->next) curr->next=curr->next->next;
        else curr->next=nullptr;
        return head;
    }
};