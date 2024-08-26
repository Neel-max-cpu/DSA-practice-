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
    
    bool findpath(TreeNode* root, TreeNode*x, vector<TreeNode*>&v){
        if(root==NULL) return false;

        v.push_back(root);
        
        
        if(root==x) {        
            return true;
        }

        
        if(findpath(root->left, x, v) || findpath(root->right, x, v)) return true;

        v.pop_back();
        return false;
        
    }

    TreeNode* helper(TreeNode*root, TreeNode*p, TreeNode*q){
        if(root==NULL) return NULL;

        if(root==p) return p;
        if(root==q) return q;

        TreeNode*left = helper(root->left, p, q);
        TreeNode*right = helper(root->right, p,q);

        if(left==NULL && right == NULL) return NULL;
        if(left!=NULL && right==NULL) return left;
        if(left==NULL && right!=NULL) return right;
        
        // if both are not null
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // brute - tc O(n+n)=2n and space O(2n)
        /*
        vector<TreeNode*>a;
        vector<TreeNode*>b;        
        findpath(root, p, a);
        findpath(root, q, b);


        int len = min(a.size(), b.size());
        for(int i=0; i<len; i++){
            if(a[i]!=b[i]) return a[i-1];
        }
        return a[len-1];
        */

        // optimized --
        return helper(root, p, q);
    }
};