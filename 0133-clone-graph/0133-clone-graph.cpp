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
    Node *helper(Node*node, unordered_map<Node*,Node*>&m){
        if(!node) return NULL;

        // if present - return the clone
        if(m.find(node)!=m.end()) return m[node];

        int val = node->val;
        Node *newNode = new Node(val);

        // save in map
        m[node] = newNode;

        vector<Node*> v = node->neighbors;
        for(int i=0; i<v.size(); i++){
            Node *neighbour = helper(v[i], m);
            newNode->neighbors.push_back(neighbour);
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {     
        unordered_map<Node*,Node*>m;
        // dfs ----
        /*   
        return helper(node, m);        
        */

        // bfs --
        if(!node) return NULL;
        int val = node->val;
        Node *copy = new Node(val);

        // put it in map
        m[node] = copy;

        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            vector<Node*> v = curr->neighbors;
            for(int i=0; i<v.size(); i++){
                Node *neighbour = v[i];
                Node *newNode = NULL;
                if(m.find(neighbour)==m.end()){
                    // if not present -- create clone, add in map, and push it in queue
                    Node *clone = new Node(neighbour->val);
                    m[neighbour] = clone;
                    q.push(neighbour);
                }
                // if present do nothing extra 

                // cloned neighbor to the cloned current node's neighbor list - common to both
                m[curr]->neighbors.push_back(m[neighbour]);
            }
        }
        return copy;
    }
};