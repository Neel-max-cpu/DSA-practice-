/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:    
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                Node*curr = q.front();
                q.pop();
                if(i==len-1){
                    // last in that level
                    curr->next = NULL;
                }
                else{
                    // not last the point to next front
                    curr->next = q.front();
                }

                // put left and right
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return root;
    }
};