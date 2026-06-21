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
    ListNode* oddEvenList(ListNode* head) {
        //M2: TC = O(n), SC = O(1)
        if(head == nullptr or head->next == nullptr) return head;
        //so cpp checks condition 1 by 1. if its or and the 1st one is true then it doesnt even check the 2nd condition. so if a condition can disrupt a program you have to place it later, so cpp only checks it if the 1st condition isnt satisfied

        ListNode* ot = head;
        ListNode* et = head->next; ListNode* eh = et;
        ListNode* temp = head->next->next;
        int count = 3;
        while(temp != nullptr){
            if(count % 2 == 1){
                ot->next = temp;
                ot = ot->next;
            }
            else {
                et->next = temp;
                et = et->next;
            }

            temp = temp->next;
            count++;
        }
        et->next = nullptr;
        ot->next = eh;
        return head;
    }
};