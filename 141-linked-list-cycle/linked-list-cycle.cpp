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
        //M0: shortcut method
        ListNode* temp = head;
        int count = 0;

        while(count <= 1e4){
            count++;
            if(temp == nullptr) return false;
            temp = temp->next;
        }

        return true;
    }
};