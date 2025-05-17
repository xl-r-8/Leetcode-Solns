/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// void dfs(Node* node, vector<vector<int>>& graph, vector<bool>& visited){

// }
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        Node* head = new Node(node->val);
        // Node* temp=head;
        queue<pair<Node*,Node*>> q;
        q.push({node,head});
        unordered_map<Node*,Node*> mp;
        mp[node]=head;
        while(!q.empty()){
            auto p=q.front();q.pop();//current node of og graph
            Node* ogNode=p.first;
            Node* cloneNode=p.second;
            for(Node* ogNeighbor: ogNode->neighbors){
                if(mp[ogNeighbor]==nullptr){
                    Node* cloneNeighbor=new Node(ogNeighbor->val);
                    cloneNode->neighbors.push_back(cloneNeighbor);
                    mp[ogNeighbor]=cloneNeighbor;
                    q.push({ogNeighbor,cloneNeighbor});
                }
                else cloneNode->neighbors.push_back(mp[ogNeighbor]);
            }
        }
        return head;
    }
};