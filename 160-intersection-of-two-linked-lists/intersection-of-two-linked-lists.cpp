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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //M1: storing in map/set
        //N1: num of nodes in LL1
        //TC=O(N1+N2) , SC=O(N1), SC can also be O(N2) if we store List 2 in map instead of list 1
    
        unordered_map<ListNode*, bool> mp; //cant do <int, bool> coz values might repeat

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != nullptr){
            mp[temp1] = true;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            if(mp.find(temp2) != mp.end()) return temp2;
            //i.e. if temp2 alr exists in mp then return temp2 otherwise move on
            temp2 = temp2->next;
        }

        return nullptr; //no common point found so return null
    }
};