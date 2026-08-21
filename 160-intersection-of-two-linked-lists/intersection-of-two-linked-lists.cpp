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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA=headA, *currB=headB;
        ListNode* intersectNode = new ListNode(0);
        vector<ListNode*> vis;
        while(currA){
            vis.push_back(currA);
            currA=currA->next;
        }

        while(currB){
            if(find(vis.begin(), vis.end(), currB)!=vis.end()){
                intersectNode=currB;
                return intersectNode;
            }
            currB=currB->next;
        }
        return nullptr;
    }
};