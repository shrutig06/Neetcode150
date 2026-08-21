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
        ListNode* pA=headA, *pB=headB;
        int cntA=0, cntB=0;
        while(pA){
            cntA++;
            pA=pA->next;
        }
        while(pB){
            cntB++;
            pB=pB->next;
        }

        cout<<cntA<<" "<<cntB<<endl;
        pA=headA; pB=headB;
        int i=cntA, j=cntB;
        while(i>cntB){
            i--;
            pA=pA->next;
        }
        while(j>cntA){
            j--;
            pB=pB->next;
        }

        while(pA && pB){
            if(pA==pB){
                return pB;
            }
            pA=pA->next;
            pB=pB->next;
        }

        return nullptr;
    }
};