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
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != nullptr and list2 != nullptr){ 
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        temp->next = (list1 != nullptr)? list1 : list2;
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //M1: brute force
        //{l1, l2, ..., lk} k sorted list
        //eg: k = 5
        //{l1, l2, l3, l4, l5} 5 sorted lists
        //l1 = merge(l1, l2); use merge2list to merge the 2 sorted lists l1 and l2 such that the resultant list is also sorted and name the result list as l1
        //{l1, l3, l4, l5}
        //l1 = merge(l1, l3)
        //{l1, l4, l5}
        //l1 = merge(l1, l4)
        //{l1, l5}
        //l1 = merge(l1, l5)
        //{l1}
        // return l1;
        //if there are n lists and every list has m nodes
        //TC = O(n*m), for each merge you would at least traverse m nodes
        //SC = O(1), coz we are not using external space and changing the given input LLs only
        if(lists.empty()) return nullptr;
        ListNode* l1 = lists[0];

        for(int i = 1; i<lists.size(); i++){
            ListNode* l2 = lists[i];
            l1 = mergeTwoLists(l1, l2);
        }

        return l1;
    }
};