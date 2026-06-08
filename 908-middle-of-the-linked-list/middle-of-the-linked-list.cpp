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
    ListNode* middleNode(ListNode* head) {
        //M1: 2 traversals, counting number of nodes
        if(head==nullptr) return head;
        int count=0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        int stop = (count/2)+1;
        temp = head;
        while(stop>1){
            temp = temp->next;
            stop--;
        }
        
        return temp;
        
    }
};