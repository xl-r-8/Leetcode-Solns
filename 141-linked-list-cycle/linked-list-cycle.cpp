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
        //M1: using visited: SC = O(n), but can we do without visited?
        unordered_set<ListNode*> st;
        ListNode* temp = head;
        while( temp != nullptr ){
            // cout<<temp->val<<endl;
            if( st.find(temp) != st.end() ){
                return true;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return false;

        //M2: without visited: sc = o(1)

    }
};