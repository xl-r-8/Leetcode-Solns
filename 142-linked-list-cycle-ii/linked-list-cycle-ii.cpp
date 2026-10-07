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
    ListNode *detectCycle(ListNode *head) {
        //M1: hash map or can use set too

        ListNode* temp = head;
        unordered_map<ListNode*, bool> mp;
 
        while(temp != nullptr){
            if(mp.find(temp) != mp.end()) return temp;
            mp[temp] = true;
            temp = temp->next;
        }
 
        return nullptr;
    }
};