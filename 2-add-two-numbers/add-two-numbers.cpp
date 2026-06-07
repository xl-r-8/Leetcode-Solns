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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        int cy = 0;
        if( l1 and l2 ){
            head = new ListNode( (l1->val + l2->val + cy) % 10 );
            cy = (l1->val + l2->val)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* p1 = head;
        while( l1 != nullptr and l2 != nullptr ){
            ListNode* p2 = new ListNode( (l1->val + l2->val + cy) % 10 );
            cy = (l1->val + l2->val + cy)/10;
            l1 = l1->next;
            l2 = l2->next;
            p1->next = p2;
            p1 = p2;
        }
        while( l1 != nullptr ){
            ListNode* p2 = new ListNode( (l1->val + cy) % 10 );
            cy = (l1->val + cy)/10;
            l1 = l1->next;
            p1->next = p2;
            p1 = p2;
        }
        while( l2 != nullptr ){
            ListNode* p2 = new ListNode( ( l2->val + cy ) % 10 );
            cy = (l2->val + cy)/10;
            l2 = l2->next;
            p1->next = p2;
            p1 = p2;
        }
        if( cy ){
            ListNode* p2 = new ListNode( cy%10 );
            cy = 0; 
            p1->next = p2;
            p1 = p2;
        }
        return head;
    }
};