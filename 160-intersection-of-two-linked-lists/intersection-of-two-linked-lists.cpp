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
        //TC=O(max(N1,N2)) , SC=O(1)
        //say N2>N1 then TC=O(N2), this is coz temp2 will move from headB to nullptr in LL2 and it will move N2 steps and loop utna hee chalega irrespective of movement of temp1

        //to do later -> check all the possible edge cases on paper

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){//if both are equal then return temp1, either they can be equal to a nodeptr or to nullptr
        //if they are not equal then move them simultaneously to next nodes
            temp1 = temp1->next;
            temp2 = temp2->next;
        //after moving if we want to teleport one of the node we have to check if both are equal before teleporting
            if(temp1 == temp2) return temp1;
        //after checking we can teleport if they follow the condition
            if(temp1 == nullptr) temp1 = headB;
            if(temp2 == nullptr) temp2 = headA;
        }
        return temp1;
    }
};