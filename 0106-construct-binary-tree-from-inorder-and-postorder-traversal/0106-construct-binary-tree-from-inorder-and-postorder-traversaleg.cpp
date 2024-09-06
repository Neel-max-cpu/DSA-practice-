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
    TreeNode *helper(int start_in, int end_in, vector<int>&inorder, int start_pos, int end_pos, vector<int>&postorder, map<int,int>&m){
        if(start_in>end_in || end_pos>start_pos) return NULL;

        int data = postorder[start_pos];
        TreeNode *root = new TreeNode(data);
        int root_ind = m[data];
        // ele in the left subtree
        int left = root_ind-start_in;
 
        root->left = helper(start_in, root_ind-1, inorder, end_pos+left-1, end_pos, postorder, m);
        root->right = helper(root_ind+1, end_in, inorder, start_pos-1, end_pos+left, postorder, m);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // in - left root right
        // post - left right root

        map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }

        TreeNode *root = helper(0, inorder.size()-1, inorder, postorder.size()-1, 0, postorder, m);
        return root;
    }
};