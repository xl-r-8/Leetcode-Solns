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
    ListNode* addTwoNumbersReversed(ListNode* &l1, ListNode* &l2) {
        //your code goes here
        ListNode* dummyNode = new ListNode( -1 );
        int cy = 0;
        ListNode* temp = dummyNode;
        while( l1 != nullptr or l2 != nullptr or cy!=0){
            int sum = cy;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* newNode = new ListNode( sum % 10 );
            cy = sum/10;
            temp->next = newNode;
            temp = newNode;
        }
        return dummyNode->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);      ;
        l2 = reverseList(l2);
        ListNode* head = addTwoNumbersReversed(l1, l2);
        head = reverseList(head);
        return head;
    }
};