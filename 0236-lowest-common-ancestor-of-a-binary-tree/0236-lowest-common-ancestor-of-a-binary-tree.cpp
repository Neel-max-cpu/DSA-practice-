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
    bool helper(TreeNode *root, TreeNode *key){
        if(root==NULL) return false;

        if(root==key) return true;

        bool left = helper(root->left, key);
        bool right = helper(root->right, key);

        return left || right;
    }

    bool getNodes(TreeNode *root, TreeNode *key, vector<TreeNode *>&v, vector<TreeNode *>temp){
        if(root==NULL) return false;

        temp.push_back(root);
        if(root==key){
            v = temp;
            return true;
        }

        bool left = getNodes(root->left, key, v, temp);
        bool right = getNodes(root->right, key, v, temp);

        temp.pop_back();

        return left||right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {


        //brute --
        /*
        // lca will be this ---
        if(root==p || root==q) return root;

        TreeNode *ans = NULL;
        // find p in left
        bool leftP = helper(root->left, p);
        // find p in right
        bool rightP = helper(root->right, p);


        // find q in left
        bool leftQ = helper(root->left, q);
        // find q in right
        bool rightQ = helper(root->right, q);

        // if both in left
        if(leftP && leftQ)
            return lowestCommonAncestor(root->left, p, q);

        // if both in right
        else if(rightP && rightQ)
            return lowestCommonAncestor(root->right, p, q);

        // if both in opposites
        else if((leftP && rightQ) || (rightP && leftQ))
            return root;
        
        // dummy
        else return root;
        */

        // better ---
        vector<TreeNode*>forP;
        vector<TreeNode*>forQ;
        vector<TreeNode*>temp;
        getNodes(root, p, forP, temp);
        getNodes(root, q, forQ, temp);
        
        TreeNode *ans = NULL;
        for(int i=0; i<min(forP.size(), forQ.size()); i++){
            if(forP[i]==forQ[i]) ans = forP[i];
            else {
                break;
            }
        }
        return ans;

    }
};