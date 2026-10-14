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
        //M2: optimal 2 ptr approach -> tampering with the given INPUT lists
        //TC = O(m+n), SC = O(1) 
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != nullptr and list2 != nullptr){ //when both temps are non NULL
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
            temp->next = nullptr;//not needed, as in the next iteration it will be automatically changed
        }

        //if list1 is still not null so list2 is null therefore attach remaining list1
        temp->next = (list1 != nullptr)? list1 : list2;
        return dummyNode->next;
    }
};