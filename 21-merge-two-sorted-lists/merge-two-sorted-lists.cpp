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
        ListNode* head=nullptr;
        if(list1==nullptr and list2==nullptr) return head;
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=nullptr;
        while(temp1!=nullptr and temp2!=nullptr){
            if(temp1->val<=temp2->val){
                ListNode* p=new ListNode(temp1->val);
                if(head==nullptr){
                    head=p;
                    temp=head;
                }
                else{
                    temp->next=p;
                    temp=temp->next;
                }
                temp1=temp1->next;
            }
            else{
                ListNode* p=new ListNode(temp2->val);
                if(head==nullptr){
                    head=p;
                    temp=head;
                }
                else{
                    temp->next=p;
                    temp=temp->next;
                }
                temp2=temp2->next;
            }
        }

        while(temp1!=nullptr){
            ListNode* p=new ListNode(temp1->val);
            if(head==nullptr){
                head=p;
                temp=head;
            }
            else{
                temp->next=p;
                temp=temp->next;
            }
            temp1=temp1->next;
        }

        while(temp2!=nullptr){
            ListNode* p=new ListNode(temp2->val);
            if(head==nullptr){
                head=p;
                temp=head;
            }
            else{
                temp->next=p;
                temp=temp->next;
            }
            temp2=temp2->next;
        }

        return head;
    }
};