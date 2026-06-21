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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return nullptr;
        ListNode* tortoise = head; ListNode* snail = nullptr;
        ListNode* rabbit = head;
        //to revise pointers and to make notes
        //to not run away from things
        while( rabbit != nullptr and rabbit->next !=nullptr ){
            snail = tortoise;
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
        }
        snail->next = tortoise->next;
        return head;
    }
};