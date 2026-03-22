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
    TreeNode *buildTree(int start_in, int end_in, vector<int>&inorder, int start_pos, int end_pos,
    vector<int>&postorder, map<int,int>&m){
        if(start_in>end_in || end_pos>start_pos) return NULL;

        int data = postorder[start_pos];        
        TreeNode *root = new TreeNode(data);

        // root index in inorder --
        int root_index = m[data];

        // lenght of left subtree --
        int left_len = root_index - start_in;        

        root->left = buildTree(start_in, root_index-1, inorder, end_pos+left_len-1, end_pos, postorder, m);
        root->right = buildTree(root_index+1, end_in, inorder, start_pos-1, end_pos+left_len, postorder, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder -- left root right
        // post order -- left right root

        /*
        inorder = 40, 20, 50, 10, 60, 30
        pre order = 10, 20, 40, 50, 30, 60
        post order = 40, 50, 20, 60, 30, 10
        */

        // similar to pre and in here just reverse
        map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }

        TreeNode *root = buildTree(0, inorder.size()-1, inorder, postorder.size()-1, 0, postorder, m);
        return root;
    }
};