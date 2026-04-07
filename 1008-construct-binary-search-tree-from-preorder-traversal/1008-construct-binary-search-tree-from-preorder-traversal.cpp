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
    TreeNode *helper(int start_in, int end_in, vector<int>&inorder, 
        int start_pre, int end_pre, vector<int>&preorder, unordered_map<int,int>&m)
    {
        if(start_in>end_in || start_pre > end_pre) return NULL;        

        int data = preorder[start_pre];
        TreeNode *root = new TreeNode(data);

        // root's index in inorder array
        int root_idx = m[data];

        // elements in the left subtree 
        int len = root_idx - start_in;

        root->left = helper(start_in, root_idx-1, inorder, start_pre+1, start_pre+len, preorder, m);
        root->right = helper(root_idx+1, end_in, inorder, start_pre+len+1, end_pre, preorder, m);
        return root;
    }

    TreeNode *helper2(vector<int>&preorder, int &i, int upperBound){
        if(i>=preorder.size() || preorder[i]>upperBound) return NULL;
        int data = preorder[i];        

        // < only works
        TreeNode *root = new TreeNode(data);
        i++;

        // when going left send the current root's data
        root->left = helper2(preorder, i, data);
        // when going right send the current root's parent's data(here upperbound is parent of current)
        root->right = helper2(preorder, i, upperBound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // brute ---
        /*
        vector<int>inorder = preorder;
        sort(inorder.begin(), inorder.end());

        //[8,5,1,7,10,12] -pre
        //[1,5,7,8,10,12] -in

        // now we have both inorder and preorder
        unordered_map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]]=i;            
        }
        TreeNode *root = helper(0, inorder.size()-1, inorder, 0, preorder.size()-1, preorder, m);
        return root;
        */

        //optimal --- 
        int i = 0;
        TreeNode *root = helper2(preorder, i, INT_MAX);
        return root;
    }
};