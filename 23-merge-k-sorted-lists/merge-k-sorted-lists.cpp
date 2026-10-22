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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // M1: using external array
        // TC: O(N + NlogN + N)
        // SC: O(N)

        vector<int> arr;

        // Step 1: Store all node values in the array
        for (ListNode* head : lists) {
            ListNode* temp = head;

            while (temp != nullptr) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }

        // Step 2: Sort all values
        sort(arr.begin(), arr.end());

        // Step 3: Construct a new sorted linked list
        ListNode dummyNode(-1);
        ListNode* temp = &dummyNode;

        for (int val : arr) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return dummyNode.next;
    }
};