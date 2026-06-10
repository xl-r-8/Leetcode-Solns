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
        // M2: without using storage, but recursive call stack will be O(n), so no point of using recursion if we want sc = o(1). for sc = o(1), we have to use iterative soln
        // May be I did something extra. But still O(N) time and O(1) space and 1ms solution in java and faster than 95.xx%.
        // Find the mid using fast pointer and slow pointer approach = O(N/2) -> O(N).
        // Reverse the first half of the list inline = O(N/2) -> O(N) time, O(1) space.
        // Compare the 2 lists. = O(N) time, O(1) space.
        // So overall: O(N) time and O(1) space.

        ListNode* temp = head;
        return rec(temp, temp);
    }
};