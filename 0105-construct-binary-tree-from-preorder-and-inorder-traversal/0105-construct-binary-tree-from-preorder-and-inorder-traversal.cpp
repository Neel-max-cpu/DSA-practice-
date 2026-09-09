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
    TreeNode*helper(int pStart, int pEnd, vector<int>&preorder, int iStart, int iEnd, vector<int>&inorder, 
    unordered_map<int,int>&m){
        if(pStart>pEnd || iStart>iEnd) return NULL;

        int rootVal = preorder[pStart];
        TreeNode*root = new TreeNode(rootVal);

        int rootIdxInorder = m[rootVal];
        // Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        int length = rootIdxInorder - iStart;

        root->left = helper(pStart+1, pStart+length, preorder, iStart, rootIdxInorder-1, inorder, m);
        root->right = helper(pStart+length+1, pEnd, preorder, rootIdxInorder+1, iEnd, inorder, m);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[inorder[i]] = i;
        }

        return helper(0, n-1, preorder, 0, n-1, inorder, m);
    }
};