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
    bool check(TreeNode*root, TreeNode*subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        if(root->val != subRoot->val) return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    void helper(TreeNode*root, TreeNode*subRoot, bool &flag){
        if(!root) return;

        if(flag) return;

        if(root->val == subRoot->val){
            bool temp = check(root, subRoot);
            if(temp) flag=true;
        }
        helper(root->left, subRoot, flag);
        helper(root->right, subRoot, flag);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag = false;        
        helper(root, subRoot, flag);
        return flag;
    }
};