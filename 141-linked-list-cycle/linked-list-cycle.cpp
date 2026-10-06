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
        //M1: using hash Map
        ListNode* temp = head;
        unordered_map<ListNode*, bool> mp;

        while(temp != nullptr){
            if(mp.find(temp) != mp.end()) return true;
            mp[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};