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
    void preorder(TreeNode*root, vector<int>&ans){
        if(root==NULL) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int>iterative(TreeNode *root){
        stack<TreeNode*>st;
        TreeNode*current = root;
        vector<int>ans;
        while(current || !st.empty()){
            while(current){
                st.push(current);
                ans.push_back(current->val);
                current = current->left;
            }
            current = st.top();
            st.pop();
            current = current->right;
        }
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // preorder -- root, left, right

        vector<int>ans;
        // recursion
        // preorder(root, ans);

        // iterative --
        ans = iterative(root);

        return ans;
                
    }
};