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
    TreeNode *helper(int start_in, int end_in, vector<int>&inorder, int start_pre, int end_pre, vector<int>&preorder, map<int,int>&m){
        if(start_in>end_in || start_pre>end_pre) return NULL;

        int data = preorder[start_pre];
        TreeNode *root = new TreeNode(data);
        
        int root_ind = m[data];
        
        // elements in the left subtree
        int len = root_ind-start_in;

        root->left = helper(start_in, root_ind-1, inorder, start_pre+1, start_pre+len, preorder, m);
        root->right = helper(root_ind+1, end_in, inorder, start_pre+len+1, end_pre, preorder, m);

        return root;        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre = root, left, right,
        // inor  = left , root, right

        map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }

        TreeNode *root = helper(0, inorder.size()-1, inorder, 0, preorder.size()-1, preorder, m);
        return root;
    }
};