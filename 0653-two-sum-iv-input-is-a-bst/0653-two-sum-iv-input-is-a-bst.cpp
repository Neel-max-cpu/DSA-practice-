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
    stack<TreeNode*>st;
    bool reverse = false;
    // reverse = false will give next bigger number (increasing)
    // reverse = true will give next smaller number (decreasing)
    BSTIterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        TreeNode *curr = root;
        pushData(curr);        
    }
    
    int next() {
        TreeNode*curr = st.top();
        st.pop();
        int ans = curr->val;
        if(reverse == false){
            // increasing order
            if(curr->right){
                curr = curr->right;
                // push left data
                pushData(curr);
            }
        }
        else{
            // decreasing
            if(curr->left){
                curr = curr->left;
                // push right data
                pushData(curr);
            }
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
            if(reverse==false){
                // pick the smallest
                curr = curr->left;
            } 
            else{
                // pick the largest
                curr = curr->right;
            }
        }
    }
};

class Solution {
public:
    void helper(TreeNode *root, vector<int>&v){
        if(!root) return;

        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // brute -- keep inorder and do
        /*
        vector<int>v;
        helper(root, v);

        int i = 0, j = v.size()-1;
        while(i<j){
            int sum = v[i]+v[j];
            if(sum==k) return true;
            else if(sum>k) j--;
            else i++;
        }
        return false;
        */

        // optimal --- using bst iterator

        // ascending
        BSTIterator l(root, false);
        // descending
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i = l.next();
            else j=r.next();
        }
        return false;
    }
};