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
    void helper(TreeNode* root, vector<int>&ans){
        // using stack
        /*
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode *curret = s.top();
            s.pop();
            ans.push_back(current->val);
            if(current->right!=NULL) s.push(current->right);
            if(current->left!=NULL) s.push(current->left);
        }
        */
        if(root==NULL) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }

    TreeNode *prev = NULL;

    void flatten(TreeNode* root) {
        // pre = root, left, right
        // brute -- 
        /*
        if(root==NULL) return;
        vector<int>ans;
        // pre
        helper(root, ans);
        for(int i=1; i<ans.size();i++){
            root->left= NULL;
            root->right = new TreeNode(ans[i]);
            root=root->right;
        } 
        */       

        // little better -- go to right most make it to the prev's right
        // take this tree - similar to eg1 just put 7 at 6's right
        /*
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
        */

        // better preorder using stack but not using new data structure --
        /*
        if(root==NULL) return;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode *current = s.top();
            s.pop();    
            if(current->right!=NULL) s.push(current->right);
            if(current->left!=NULL) s.push(current->left);
            if(!s.empty()){
                current->right = s.top();
            }            
            current->left = NULL;
        }
        */

        // best - using morris traversal -- basically connect the rightmost of leftsubtree to root's right, then make
        // root->right = root->left;
        TreeNode *current = root;
        while(current !=NULL){
            if(current->left!=NULL){
                TreeNode*prev = current->left;
                while(prev->right!=NULL){
                    prev = prev->right;
                }
                prev->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current=current->right;
        }

    }
};