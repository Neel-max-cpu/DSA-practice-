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

class Solution {
public:
    unordered_map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;           
        /*
        cout<<node->val<<": ";
        for(int i=0; i<node->neighbors.size(); i++){
            cout<<node->neighbors[i]->val<<" ";
        }
        cout<<endl;         
        return NULL;
        */

        // using dfs ---
        if(m.find(node)==m.end()){
            // if node not found -- create a node wiht empyt vector
            m[node] = new Node(node->val);
            for(int i=0; i<node->neighbors.size(); i++){
                Node *neighbor = node->neighbors[i];
                m[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return m[node];

        // // using bfs
        // unordered_map<Node*,Node*>m;
        // Node *copy = new Node(node->val);

    }
};