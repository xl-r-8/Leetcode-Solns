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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* grpHead = temp;
        ListNode* grpTail;
        int count = 0; 
        ListNode* nextGrpNode;
        ListNode* prevGrpNode = nullptr;
        while(temp != nullptr){
            count++;
            if(count == k){
                nextGrpNode = temp->next;
                grpTail = temp; 
                grpTail->next = nullptr;
                if(prevGrpNode) prevGrpNode->next = nullptr;
                else head = grpTail;
                
                reverseList(grpHead);

                if(prevGrpNode)prevGrpNode->next = grpTail;
                grpHead->next = nextGrpNode;
                prevGrpNode = grpHead;
                temp = nextGrpNode;
                grpHead = nextGrpNode;
                count = 0;
            }
            else temp = temp->next;
        }

        return head;
    }
};