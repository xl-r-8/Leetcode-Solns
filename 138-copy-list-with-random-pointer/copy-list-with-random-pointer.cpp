/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //M2: using the given list 
        //TC: O(2N)
        //SC: O(N), deep-copied list(it's ans so ask interviewer)
        if(head == nullptr) return nullptr;

        Node* temp = head;

        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        Node* head2 = head->next;
        while(temp != nullptr){
            Node* node = temp->next;

            Node* tempRandom = temp->random;
            Node* nodeRandom = (tempRandom == nullptr)? nullptr: tempRandom->next;
            node->random = nodeRandom;

            temp = node->next;
        }

        temp = head;
        while(temp != nullptr){
            Node* node = temp->next;

            Node* tempNext = node->next;
            Node* nodeNext = (tempNext == nullptr)? nullptr: tempNext->next;
            node->next = nodeNext;
            temp->next = tempNext;

            temp = temp->next;
        }
        
        return head2;
    }
};