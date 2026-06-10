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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;

        //M1: using 3 ptrs
        ListNode* back = nullptr; 
        ListNode* cur = head;
        ListNode* front = nullptr;
        if( head ) front = head->next ;
        // else ListNode* front = nullptr;
        while( cur != nullptr ){
            // cout<< cur->val <<endl;
            cur->next = back; 
            back = cur;
            cur = front;
            if( front ) front = front->next; //front can be nullptr when cur = tail so only move front when cur is not tail
            
        }
        head = back;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return true;
        ListNode* tortoise = head;
        ListNode* rabbit = head;
        ListNode* snail = nullptr;
        //to revise pointers and to make notes
        //to not run away from things
        while( true ){
            snail = tortoise;
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            if(rabbit == nullptr){ 
                snail->next = reverseList(tortoise);
                break;
            }
            if(rabbit->next == nullptr){
                tortoise->next = reverseList(tortoise->next);
                snail = tortoise;
                break;
            }
        }

        ListNode* t1 = head; 
        ListNode* t2 = snail->next;

        while(t2 != nullptr){
            if(t1->val != t2->val) return false;
            t1 = t1->next;
            t2 = t2->next;
        }

        return true;
    }
};