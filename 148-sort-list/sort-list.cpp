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
    ListNode* sortList(ListNode* head) {
        //M1: using external arr
        //TC: O(N + N logN + N)
        //SC: O(N)

        vector<int> v;

        //O(N)
        ListNode* temp = head;
        while(temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }

        //O(N logN)
        sort(v.begin(), v.end());

        //O(N)
        temp = head; int i = 0;
        while(temp != nullptr){
            temp->val = v[i];
            temp = temp->next;
            i++;
        }

        return head;
    }
};