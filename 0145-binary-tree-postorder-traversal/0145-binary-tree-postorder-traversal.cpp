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
    void recursion(TreeNode*root, vector<int>&ans){
        if(root==NULL) return;

        recursion(root->left, ans);
        recursion(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int>iterative(TreeNode*root){        
        vector<int>ans;
        stack<TreeNode*>st1;
        stack<int>st2;
        if(root)
            st1.push(root);

        while(!st1.empty()){
            TreeNode*current = st1.top();
            st1.pop();
            st2.push(current->val);
            if(current && current->left) st1.push(current->left);
            if(current && current->right) st1.push(current->right);
        }

        while(!st2.empty()){            
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // left, right, root

        vector<int>ans;
        // recursion(root, ans);

        ans = iterative(root);
        return ans;
    }
};