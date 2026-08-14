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
    bool hasCycle(ListNode *head) {
        vector<ListNode*> nodes;
        ListNode* curr=head;
        while(curr){
            auto it=find(nodes.begin(), nodes.end(), curr);
            if(it!=nodes.end()) return true;
            nodes.push_back(curr);
            curr=curr->next;
        }

        return false;
    }
};