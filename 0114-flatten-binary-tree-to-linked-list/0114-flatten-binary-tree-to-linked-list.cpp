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
    void helper(TreeNode*root){
        if(!root) return;
        TreeNode *right = root->right;

        TreeNode*dummy = NULL;
        if(root->left){
            dummy = root->left;
            while(dummy->right){
                dummy = dummy->right;
            }            
            dummy->right = right;
            root->right = root->left;
            root->left = NULL;
            helper(root->right);
        }
        else{
            helper(root->right);
        }
    }

    void flatten(TreeNode* root) {
        if(!root) return;
        helper(root);        
    }
};