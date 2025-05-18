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
void dfs(pair<Node*,Node*> p,  unordered_map<Node*,Node*>& mp){
    Node* ogNode=p.first;
    Node* cloneNode=p.second;
    mp[ogNode]=cloneNode;
    for(Node* ogNeighbor: ogNode->neighbors){
        if(mp[ogNeighbor]==nullptr){
            Node* cloneNeighbor=new Node(ogNeighbor->val);
            cloneNode->neighbors.push_back(cloneNeighbor);
            dfs({ogNeighbor,cloneNeighbor},mp);
        }
        else cloneNode->neighbors.push_back(mp[ogNeighbor]);
    }
}

Node* bfs(Node* node){
    Node* head = new Node(node->val);
    // Node* temp=head;
    queue<pair<Node*,Node*>> q;
    q.push({node,head});
    unordered_map<Node*,Node*> mp;
    //why did i change from <Node*, bool> to <Node*, Node*>?
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
            // why did i add an else?
        }
    }
    return head;
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        // return bfs(node);
        Node* head = new Node(node->val);
        unordered_map<Node*,Node*> mp;//unordered_map<Node*&,Node*&> mp; is this allowed? actually this is not needed coz you are already sending Node* A POINTER and not a node. it's like sending an array, you dont need & for it.
        dfs({node,head},mp);
        return head;
    }
};