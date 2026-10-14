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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr or head->next == nullptr) return head;
        ListNode* tail; int length = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            length++;
            if(temp->next == nullptr) tail = temp;
            temp = temp->next;
        }
        //rot = 11, length = 5
        int rot = k%length; //rot = 1
        int count = length - rot; //rot = 4
        tail->next = head;
        //now we have a cyclic list
        //we just have to break the correct edge
        //and choose the correct head
        temp = head;

        while(count > 0 and temp != nullptr){
            count--;
            if(count == 0){
                head = temp->next;
                temp->next = nullptr;
            }
            temp = temp->next;
        }
        return head;
    }
};