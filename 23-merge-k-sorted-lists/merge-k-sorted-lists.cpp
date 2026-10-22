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
        //M4: divide and conquer
        //TC:
        //SC:

        queue<ListNode*> q;
        for(int i = 0; i<lists.size(); i++){
            if(lists[i] != nullptr) q.push(lists[i]);
        }
        
        while(q.size()>1){
            ListNode* list1 = q.front(); q.pop();
            if(q.empty()){
                q.push(list1);
                break;
            }
            ListNode* list2 = q.front(); q.pop();
            ListNode* newList = mergeTwoLists(list1, list2);
            q.push(newList);
        }

        if(q.empty()) return nullptr;
        return q.front();
    }
};