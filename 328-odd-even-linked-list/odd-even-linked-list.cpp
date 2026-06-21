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
        //M1: TC = O(n), SC = O(n)
        //separate odd and even linked lists

        if(head == nullptr) return nullptr;

        ListNode* ho = new ListNode(head->val); ListNode* to = ho;
        // is this possible ListNode* ho(head->val);
        // ListNode* he; does this mean he is nullptr or do we have to explicitly specify he = nullptr
        if(head->next == nullptr) return ho; //why arrow instead of dot. pointer revision. class and struct revision.
        ListNode* he = new ListNode(head->next->val); ListNode* te = he;
        ListNode* temp = head->next->next;
        int count = 3;
        while(temp != nullptr){
            if(count % 2 == 1){
                to->next = new ListNode(temp->val);
                to = to->next;
            }
            else{
                te->next = new ListNode(temp->val);
                te = te->next;
            }
            temp = temp -> next;
            count++;
        }
        to->next = he;
        return ho;


        
    }
};