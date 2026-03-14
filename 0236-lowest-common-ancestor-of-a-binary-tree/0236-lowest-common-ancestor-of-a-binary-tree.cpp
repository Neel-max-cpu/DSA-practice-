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
    bool helper(TreeNode *root, TreeNode *key){
        if(root==NULL) return false;

        if(root==key) return true;

        bool left = helper(root->left, key);
        bool right = helper(root->right, key);

        return left || right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // lca will be this ---
        if(root==p || root==q) return root;

        TreeNode *ans = NULL;
        // find p in left
        bool leftP = helper(root->left, p);
        // find p in right
        bool rightP = helper(root->right, p);


        // find q in left
        bool leftQ = helper(root->left, q);
        // find q in right
        bool rightQ = helper(root->right, q);

        // if both in left
        if(leftP && leftQ)
            return lowestCommonAncestor(root->left, p, q);

        // if both in right
        else if(rightP && rightQ)
            return lowestCommonAncestor(root->right, p, q);

        // if both in opposites
        else if((leftP && rightQ) || (rightP && leftQ))
            return root;
        
        // dummy
        else return root;

    }
};