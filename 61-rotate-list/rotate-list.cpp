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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        
        ListNode* temp = head; int n = 0 ;

        while( temp != nullptr ){
            temp = temp-> next;
            n++;
        }
        k = k%n;
        if(k == 0) return head; //n==1 also => k==0
        
        int count = 0;
        temp = head;
        ListNode* head2;

        while(temp->next != nullptr){
            count++;
            ListNode* prev = temp;
            temp = temp->next;
            if(count == n-k){
                head2 = prev->next;
                prev->next = nullptr;
            } 
        }
        temp->next = head;
        return head2;
    }
};