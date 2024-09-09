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

    bool findpath(TreeNode*root, TreeNode*x, vector<TreeNode*>&v){
        if(root==NULL) return false;
        v.push_back(root);
        if(root==x) return true;
        if(findpath(root->left, x, v) || findpath(root->right, x, v)) return true;
        v.pop_back();
        return false;
    }

    void helper(TreeNode*root, TreeNode *x, vector<TreeNode*>&v){
        // we can also use find path used to find in binary tree, but since bst have
        // >then right, else left, so we can use the property

        if(root==NULL) return;
        v.push_back(root);
        if(root->val == x->val) return;
        if(root->val> x->val) helper(root->left, x, v);
        else helper(root->right, x, v);

    }

    TreeNode *helper2(TreeNode *root, TreeNode*p, TreeNode*q){
        // o(h) = height
        // /*
        if(root==NULL) return NULL;
        int data = root->val;
        int a = p->val;
        int b = q->val;

        if(data>a && data>b) return helper2(root->left, p, q);
        else if(data<a && data<b) return helper2(root->right, p, q);       
        else return root;
        // */

        // in binary tree - o(n)
        /*
        if(root==NULL || root==p || root==q) return root;
        TreeNode *left = helper2(root->left, p, q);
        TreeNode*right = helper2(root->right, p, q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
        */
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // brute - o(h)+o(h)+o(h) ~ o(n) worst case 
        if(root==NULL) return root;
        /*
        vector<TreeNode*>a; 
        vector<TreeNode*>b;
        // using bst property        
        // helper(root, p, a);
        // helper(root, q, b);

        // using find path        
        findpath(root,p,a);
        findpath(root,q,b);
        int len = min(a.size(), b.size());
        for(int i=0; i<len; i++){
            if(a[i]!=b[i]) return a[i-1];
        }
        return a[len-1];
        */
        return helper2(root, p, q);
    }
};