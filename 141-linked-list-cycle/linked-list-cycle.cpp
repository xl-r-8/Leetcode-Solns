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
        unordered_set<ListNode*> st;//cant store values in set, coz they can be repeated, but address of each node is unique or ListNode* ptr for each node is unique
        // ListNode* temp = head;
        // while( temp != nullptr ){
        //     // cout<<temp->val<<endl;
        //     if( st.find(temp) != st.end() ){
        //         return true;
        //     }
        //     st.insert(temp);
        //     temp=temp->next;
        // }
        // return false;

        //M2: without visited: sc = o(1)
        //weird method: but since ik the max nodes in this ques can be 10^4, so i initialize a temp ptr as head then keep on moving it(temp=temp->next) and i will keep a counter which will count the num of nodes or num of iterations
        //All those linked list with no loop will stop before count exceeds 10^4, but those with loop will exceed it
        //Incorrect method but a clever trick
        int count = 0;
        ListNode* temp = head;
        while( temp != nullptr ){
            count++;
            temp = temp->next;
            if(count>1e4) return true;
        }
        return false;
    }
};