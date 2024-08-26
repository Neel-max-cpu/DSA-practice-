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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a;
        vector<TreeNode*>b;        
        findpath(root, p, a);
        findpath(root, q, b);

        for(auto it:a) cout<<it->val<<" ";
        cout<<endl;
        for(auto it:b) cout<<it->val<<" ";

        int len = min(a.size(), b.size());
        for(int i=0; i<len; i++){
            if(a[i]!=b[i]) return a[i-1];
        }
        return a[len-1];
        

    }
};