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
        //l1 = merge(l1, l2); //merge 1
        //use merge2list to merge the 2 sorted lists l1 and l2 such that the resultant list is also sorted and name the result list as l1
        //{l1, l3, l4, l5}
        //l1 = merge(l1, l3) //merge 2
        //{l1, l4, l5}
        //l1 = merge(l1, l4) //merge 3
        //{l1, l5}
        //l1 = merge(l1, l5) //merge 4
        //{l1}
        // return l1;
        //SC = O(1), coz we are not using external space and changing the given input LLs only

        //tc 2 ways: taking O(min(m,n)) as tc of merge2lists
        //say each of 5(=k) lists has n nodes, 4(=k-1) merges each involving at least n nodes => tc = O(n*k)
        //TC = O(n*k), for each merge you would at least traverse n nodes

        //taking O(m+n) as tc of merge2lists
        //each of 5(=k) lists has n nodes
        //merge 1 -> n+n
        //merge 2 -> 2n+n = n+n+n
        //merge 3 -> 3n+n = n+n+n+n
        //merge 4 -> 4n+n = n+n+n+n+n
        //tc is approx k*n + (k-1)*n + (k-2)*n ... +1*n (actually it would be  2*(k-1)*n + (k-2)*n + (k-3)*n +...1*n)
        //tc = n(k(k+1)/2)
        //tc = O(n*(k^2))

        if(lists.empty()) return nullptr;
        ListNode* l1 = lists[0];

        for(int i = 1; i<lists.size(); i++){
            ListNode* l2 = lists[i];
            l1 = mergeTwoLists(l1, l2);
        }

        return l1;
    }
};