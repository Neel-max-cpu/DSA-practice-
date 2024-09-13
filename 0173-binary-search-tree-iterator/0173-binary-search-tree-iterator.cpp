/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    // method 1 --
    /*
    vector<int>v;
    int i = 0;
    int size;
    */
    
    // method 2 
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        // method 1
        /*
        TreeNode *temp = root;
        stack<TreeNode*>s;
        while(temp!=NULL || !s.empty()){
            while(temp!=NULL) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            v.push_back(temp->val);
            temp = temp->right;
        }
        size = v.size();
        */

        // method 2
        // put all left, everything on the stack
        TreeNode*temp = root;
        while(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        // method 1
        /*
        return v[i++];
        */
        
        // method 2 - take the top and put all the right into the stack
        TreeNode *current = s.top();
        s.pop();
        int ans = current->val;
        if(current->right!=NULL) {
            current=current->right;
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        // method 1
        /*
        if(i<size) return true;
        else return false;
        */

        // method2 
        if(!s.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */