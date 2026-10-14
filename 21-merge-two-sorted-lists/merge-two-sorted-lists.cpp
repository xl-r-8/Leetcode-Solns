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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //M1: using external array to store sort and make list
        //TC = O(m+n log(m+n)), SC = O(m+n) 
        
        vector<int> v;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        //O(m+n)
        while(temp1 != nullptr or temp2 != nullptr){
            int ele1 = (temp1 == nullptr)? INT_MAX : temp1->val;
            int ele2 = (temp2 == nullptr)? INT_MAX : temp2->val;

            if(ele1 <= ele2) {
                v.push_back(ele1);
                temp1 = temp1->next;
            }
            else{
                v.push_back(ele2);
                temp2 = temp2->next;
            }
        }

        //O(m+n log(m+n))
        sort(v.begin(), v.end());

        //O(m+n)
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for(int i = 0; i<v.size(); i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }

        return dummyNode->next;
    }
};