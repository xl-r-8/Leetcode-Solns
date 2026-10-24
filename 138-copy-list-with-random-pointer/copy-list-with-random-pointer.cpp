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
        //M1: using map 
        if(head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* dummyNode = new Node(-1);

        Node* temp = head;

        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }

        Node* head2 = mp[head];

        temp = head;

        while(temp != nullptr){
            Node* nextTemp = temp->next;
            Node* randTemp = temp->random;

            Node* node = mp[temp];
            if(nextTemp != nullptr) node->next = mp[nextTemp];
            if(randTemp != nullptr) node->random = mp[randTemp];
            temp = temp->next;
        }

        return head2;
        
    }
};