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
    TreeNode *helper(int start_pre, int end_pre, vector<int>&pre, int start_in, int end_in, vector<int>&in, map<int,int>&m){
        if(start_pre>end_pre || start_in>end_in) return NULL;
        
        int data = pre[start_pre];
        TreeNode *root = new TreeNode(data);
        int ind = m[data];
        int left = ind-start_in;

        root->left = helper(start_pre+1, start_pre+left, pre, start_in, ind-1, in, m);
        root->right = helper(start_pre+left+1, end_pre, pre, ind+1, end_in, in, m);
        return root;
    }

    TreeNode *helper2(vector<int>&pre, int&i, int n, int upper_bound){
        if(i==n || pre[i]>upper_bound) return NULL;        

        TreeNode *root = new TreeNode(pre[i]);
        i++;
        root->left = helper2(pre, i, n, root->val);
        root->right = helper2(pre, i, n, upper_bound);
        return root;    
    }

    TreeNode* bstFromPreorder(vector<int>& v) {
        // preorder - node, left, right
        // inorder of a bst is sorted array

        // o(nlogn)+o(n)
        /*
        int n = v.size();
        vector<int>a = v;
        sort(a.begin(), a.end());
        // now similar to make a binary tree using preorder and inorder
        map<int,int>m;
        for(int i=0; i<n; i++) m[a[i]]= i;
        TreeNode *root = helper(0, n-1, v, 0, n-1, a, m);
        return root;
        */

        // optimised o(n)
        int n = v.size();
        int i = 0;
        TreeNode*root = helper2(v, i, n, INT_MAX);
        return root;
    }
};