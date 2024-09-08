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
    bool helper(TreeNode*root, long a, long b){
        if(root==NULL) return true;

        bool f1 = helper(root->left, a, root->val);
        bool f2 = helper(root->right, root->val, b);

        // all must be true return true else false (generally right subtree >= but here given > only question)
        return ((root->val>a && root->val<b) && f1 && f2);
    }

    bool isValidBST(TreeNode* root) {
        // starting node's range INT_MIN,
        // 2147483647-max -2147483648-min
        if(root==NULL) return true;
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};