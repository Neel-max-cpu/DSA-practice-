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
    // brute -- using vector and save
    // optimal --
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        pushData(curr);        
    }
    
    int next() {
        TreeNode*curr = st.top();
        st.pop();
        int ans = curr->val;
        if(curr->right){
            curr = curr->right;
            pushData(curr);
        }      
        return ans;                  
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else return false;
    }

    private:
    void pushData(TreeNode*curr){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */