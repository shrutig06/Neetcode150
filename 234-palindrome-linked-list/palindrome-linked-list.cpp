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
        vector<int> list;
        while(curr){
            list.push_back(curr->val);
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        vector<int> revList(list.size());
        reverse_copy(list.begin(), list.end(), revList.begin());
        return list==revList;
    }
};