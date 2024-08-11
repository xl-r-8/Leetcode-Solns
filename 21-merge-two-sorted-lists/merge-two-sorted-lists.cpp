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
    void addNode(ListNode*&head,int data){
        ListNode* p=new ListNode(data);
        if(head==nullptr) {
            head=p;return;
        }
        ListNode* temp=head;
        while(temp->next!=nullptr) temp=temp->next;
        temp->next=p; p->next=nullptr;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3=nullptr;
        while(list1!=nullptr and list2!=nullptr){
            if(list1->val<=list2->val){
                addNode(list3,list1->val);
                list1=list1->next;
            }
            else{ 
                addNode(list3,list2->val);
                list2=list2->next;    
            }
        }
        while(list1!=nullptr ){
            addNode(list3,list1->val);
            list1=list1->next;
        }
        while(list2!=nullptr ){
            addNode(list3,list2->val);
            list2=list2->next;   
        }
        return list3;
    }
};