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
        //see traversal in cyclic list would go on for infinity. so if you count then it would definitely exceed the num of possible nodes that the given structure can maximally hold. and for acyclic lists it would have less than 10^4 nodes and temp would reach nullptr before count exceeds 10^4
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