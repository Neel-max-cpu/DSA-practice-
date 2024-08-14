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
    void helper(TreeNode *root, vector<int>&ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder -- root left right
        vector<int>ans;

        // recursive ---
        // helper(root, ans);

        // iterative ---
        // /*
        stack<TreeNode*>s;
        TreeNode*current = root;

        if(root!=NULL) s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            ans.push_back(node->val);

            // since stack so push the right child first to process the left one first
            if(node->right!=NULL){
                s.push(node->right);
            }
            if(node->left != NULL){
                s.push(node->left);
            }
        }
        return ans;
        // */

        // Morris traversal ---

    }
};