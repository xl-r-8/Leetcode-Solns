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
        //M3: tortoise - rabbit method
        if(head == nullptr or head->next == nullptr) return false;
        ListNode* tortoise = head;
        ListNode* rabbit = head->next;
        while( rabbit != nullptr ){
            if(tortoise == rabbit) return true;
            tortoise = tortoise->next;
            if(rabbit->next == nullptr or rabbit->next->next == nullptr) break;
            rabbit = rabbit->next->next;
        }
        return false;
    } 
};