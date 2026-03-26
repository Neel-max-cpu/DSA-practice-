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
        
        // better - o(n) and sc - o(n)
        /*
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
        */

        // optimal -- o(n) ans sc - o(1) (skipping the queue)
        Node *start = root;                
        while(start){
            // keeping this for vertical travelling
            Node *curr = start;
            while(curr){
                // travel horizontally ---
                // connect left and right
                if(curr->left && curr->right){
                    curr->left->next = curr->right;
                }   
                // connect right to next's left    
                if(curr->right && curr->next && curr->next->left){
                    curr->right->next = curr->next->left;
                }

                // move to next
                curr = curr->next;                
            }
            // move left most since we finished travelling level wise
            start = start->left;
        }
        return root;

    }
};