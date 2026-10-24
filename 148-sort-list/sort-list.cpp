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
        ListNode dummyNode(-1);//stack allocated dummy node
        ListNode* temp = &dummyNode;

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
        return dummyNode.next;
    }

    ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* rabbit = head;

        while( rabbit != nullptr and rabbit->next !=nullptr and rabbit->next->next != nullptr ){
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
        }
        return tortoise;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == nullptr or head->next == nullptr) return head;

        ListNode* middle = middleOfLinkedList(head);

        ListNode* left = head; ListNode* right = middle->next;
        middle->next = nullptr;

        left = mergeSort(left);
        right = mergeSort(right);

        head = mergeTwoLists(left, right);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        //M2: using any sorting algo
        //the best sort algos are merge sort and quick sort
        //this just includes implementation of merge sort, other algos can be implemented similarly
        //TC: O(N logN)
        //SC: O(logN)

        head = mergeSort(head);

        return head;
    }
};