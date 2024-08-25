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
    int find_height(TreeNode*root){
        if(root==NULL) return 0;
        
        /*
        int left=0, right=0;
        if(root->left!=NULL){
            left = find_height(root->left);
        }

        if(root->right!=NULL){
            right = find_height(root->right);
        }
        */
        
        // since already returning 0 when null
        
        int left = find_height(root->left);
        int right = find_height(root->right);
        

        return max(left,right)+1;
    }

    int maxDepth(TreeNode* root) {


        // method 1 --
        /*
        int n = 0;
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int len = q.size();
            n++;
            for(int i=0; i<len; i++){
                auto p = q.front();
                q.pop();
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
            }
        }
        return n;
        */

        // method 2 ---
        return find_height(root);
        
        
    }
};