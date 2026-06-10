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
    bool rec(ListNode* &i, ListNode* j){
        if(j == nullptr) return true;
        if(rec(i, j->next) == false) return false;
        if(i->val != j->val) return false;
        i = i->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        // M2: without using storage
        ListNode* temp = head;
        return rec(temp, temp);
        
    }
};