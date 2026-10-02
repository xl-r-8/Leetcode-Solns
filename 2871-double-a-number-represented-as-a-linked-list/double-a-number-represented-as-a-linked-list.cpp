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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //m2: without actually reversing the list
        //using stack to virtually reverse the list
        stack<ListNode*> s1;
        ListNode* temp = l1;
        while(temp != nullptr){
            s1.push(temp);
            temp = temp->next;
        }
        
        stack<ListNode*> s2;
        temp = l2;
        while(temp != nullptr){
            s2.push(temp);
            temp = temp->next;
        }

        int cy = 0;//can take values 0 or 1
        ListNode* dummyNode = new ListNode(-1);//instead of -1 Node we can create a dummyNode of nullptr, no (ListNode(0))its not a dummyNode of nullptr, its a dummyNode of 0
        //when Node* when Node and when -> when .? wdym by new Node?

        while(!s1.empty() or !s2.empty() or cy>0){
            int sum = cy;
            ListNode* temp1 = nullptr;
            ListNode* temp2 = nullptr;
            if(!s1.empty()){
                temp1 = s1.top(); s1.pop();
                sum += temp1->val;
            } 
            if(!s2.empty()){
                temp2 = s2.top(); s2.pop();
                sum += temp2->val;
            } 

            //instead of reversing in the end, we can just create 2 nodes and reverse the links from there on only
            ListNode* newNode = new ListNode(sum%10);
            if(dummyNode->val == -1) newNode->next = nullptr;
            else newNode->next = dummyNode;
            dummyNode = newNode;
            cy = sum/10;
        }

        return dummyNode;

    }
    ListNode* doubleIt(ListNode* head) {
        return addTwoNumbers(head, head);
    }
};