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
class Solution {
public:
    void helper(TreeNode*root, int& counter, int k, int &ans){
        if(root==NULL || counter>=k) return;
        helper(root->left, counter, k, ans);
        counter++;
        if(counter==k) {
            ans = root->val;
            return;
        }
        helper(root->right, counter, k, ans);
    }

    void helper2(TreeNode*root, int& counter, int k, int &ans){
        if(root==NULL || counter>=k) return;
        helper2(root->right, counter, k, ans);
        counter++;
        if(counter==k) {
            ans = root->val;
            return;
        }
        helper(root->left, counter, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        // brute -- o(n)
        /*
        vector<int>ans;
        // inorder - left root right
        stack<TreeNode*>s;
        TreeNode*current = root;        
        while(!s.empty() || current!=NULL){
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            current = s.top();
            s.pop();
            ans.push_back(current->val);
            current=current->right;
        }
        return ans[k-1];
        */

        // optimal - using counter -- k smallest
        int ans= 0;
        int counter = 0;
        helper(root,counter,k, ans);
        return ans;

        // k largest 
        /*   
        int ans = 0;
        int counter = 0;
        helper2(root, counter, k, ans);
        return ans;
        */
    }
};