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

class BSTIterator{
    stack<TreeNode*>s;
    bool reverse = false;

public:
    BSTIterator(TreeNode*root, bool is_reverse){
        reverse = is_reverse;
        pushAll(root);
    }

    bool hasNext(){
        return !s.empty();
    }

    int next(){
        TreeNode *current = s.top();
        s.pop();
        if(!reverse) pushAll(current->right);
        else pushAll(current->left);
        return current->val;
    }

private:
    void pushAll(TreeNode*root){
        while(root!=NULL){
            s.push(root);
            if(reverse==true) root=root->right;
            else root=root->left;
        }
    }

};

class Solution {
public:
    void helper(TreeNode*root, vector<int>&ans){
        if(root==NULL) return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        // brute - o(n)+o(n);
        /*
        vector<int>ans;
        helper(root, ans);
        int i=0, j=ans.size()-1;
        while(i<j){
            int sum = ans[i]+ans[j];
            if(sum==k) return true;
            else if(sum>k){
                j--;
            }
            else i++;
        }
        return false;
        */

        // optimal 
        // used bst iterator next() and before()
        // next - insorted order, and before - in decending order
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();   
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i = l.next();
            else j = r.next();
        }
        return false;


    }
};