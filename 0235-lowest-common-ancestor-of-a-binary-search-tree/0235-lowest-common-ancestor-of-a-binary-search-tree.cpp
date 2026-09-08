/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void check(TreeNode*root, TreeNode*p, TreeNode*q, bool &one, bool &two){
        if(!root) return;
        
        if(root==p) one = true;
        if(root == q) two = true;

        if(one && two) return;

        check(root->left, p, q, one, two);
        check(root->right, p, q, one, two);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        if(root == p || root == q) return root;

        bool lp = false, lq = false;
        check(root->left, p, q, lp, lq);

        // if both on the left
        if(lp && lq){
            // go left
            return lowestCommonAncestor(root->left, p, q);
        }

        bool rp = false, rq = false;
        check(root->right, p,q, rp, rq);

        // if both on right
        if(rp && rq){
            // go right
            return lowestCommonAncestor(root->right, p, q);
        }

        // if both different
        return root;
    }
};