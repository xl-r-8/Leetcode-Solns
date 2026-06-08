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
        //M2: tortoise-rabbit method
        ListNode* tortoise = head;
        ListNode* rabbit = head;
        //to revise pointers and to make notes
        //to not run away from things
        while( rabbit != nullptr and rabbit->next !=nullptr ){
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
        }
        return tortoise;
        
    }
};