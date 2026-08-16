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
    bool isPalindrome(ListNode* head) {
        ListNode* prev=nullptr, *curr;
        curr=head;
        vector<int> list, revList;
        while(curr){
            list.push_back(curr->val);
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        while(prev){
            revList.push_back(prev->val);
            prev=prev->next;
        }

        return list==revList;
    }
};