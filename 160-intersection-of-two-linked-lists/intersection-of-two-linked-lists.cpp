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
        //M2: 2ptr
        //N1: num of nodes in LL1
        //TC=O() , SC=O()
    

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){//if both are equal then return temp1
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2) return temp1;

            if(temp1 == nullptr) temp1 = headB;
            if(temp2 == nullptr) temp2 = headA;
        }
        return temp1;
    }
};