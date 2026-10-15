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
    struct comparator{
        bool operator()(ListNode* a, ListNode* b) {    
            return a->val > b->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
        for(int i = 0; i<lists.size(); i++){
            if(lists[i] != nullptr) pq.push(lists[i]);
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(!pq.empty()){
            ListNode* node = pq.top(); pq.pop();
            temp->next = node;
            temp = temp->next;
            node = node->next;
            if(node != nullptr) pq.push(node);
        }
        return dummyNode->next;
    }
};