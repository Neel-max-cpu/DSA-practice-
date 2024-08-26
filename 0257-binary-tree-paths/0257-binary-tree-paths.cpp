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

    void helper(TreeNode*root, vector<string>&ans, string t){   

        t+=to_string(root->val);
        t+="->";
        
        if(root->left==NULL && root->right==NULL){
            t.pop_back();
            t.pop_back();
            ans.push_back(t);
            return;
        }

        if(root->left!=NULL){
            helper(root->left, ans, t);
        }

        if(root->right!=NULL)
            helper(root->right, ans, t);
        
        t.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        helper(root, ans, "");
        return ans;
    }
};