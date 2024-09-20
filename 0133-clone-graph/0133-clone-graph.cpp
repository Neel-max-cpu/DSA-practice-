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
        /*
        if(m.find(node)==m.end()){
            // if node not found -- create a node with empty vector
            // map the original node to the new copy node
            m[node] = new Node(node->val);
            for(int i=0; i<node->neighbors.size(); i++){
                Node *neighbor = node->neighbors[i];
                m[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return m[node];
        */

        // using bfs ---
        Node *copy = new Node(node->val);
        m[node] = copy;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(int i=0; i<curr->neighbors.size();i++){
                Node *neighbor = curr->neighbors[i];
                if(m.find(neighbor)==m.end()){
                    // if not present
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        return copy;
    }
};