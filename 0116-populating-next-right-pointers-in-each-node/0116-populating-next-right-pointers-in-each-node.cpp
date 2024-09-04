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
        if(root==NULL) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node *prev = q.front();
            q.pop();
            if(prev->left!=NULL){
                q.push(prev->left);
                q.push(prev->right);
            }
            for(int i=1; i<size; i++){
                Node *current = q.front();
                q.pop();
                prev->next = current;
                current->next = NULL;
                prev = current;
                if(current->left!=NULL){
                    q.push(current->left);
                    q.push(current->right);
                }
            }
        }
        return root;
    }
};