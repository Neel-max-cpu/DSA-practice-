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
        Node *curr = root;
        Node *prev = NULL;
        int count = 1;
        while(curr){
            if(curr->left && curr->right){
                // left points to right
                curr->left->next = curr->right;
                // right points to null
                curr->right->next = NULL;
            }
            if(prev){
                // if prev is present then prev's next will point to left
                prev->next = curr->left;
            }

            if(count>=2){
                // we want it to work from 3rd level so update it from 2nd level
                prev = curr->right;
            }

            // move to root to left (if root's next point to null else move next)
            if(curr->next) curr = curr->next;
            else curr= curr->left;

            count++;
        }
        return root;

    }
};