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
        // pre order = root, left, right
        // brute -- 
        /*
        if(root==NULL) return;
        vector<int>ans;
        // pre order
        helper(root, ans);
        for(int i=1; i<ans.size();i++){
            root->left= NULL;
            root->right = new TreeNode(ans[i]);
            root=root->right;
        } 
        */       

        // little better -- go to right most make it to the prev's right (kinda right left root traversal)
        // take this tree - similar to eg1 just put 7 at 6's left
        /*
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
        */

        // better preorder using stack but not using new data structure --- same as above(recursion)
        // since stack as the last as the top most ele
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

        // best - using morris traversal -- basically connect the rightmost of leftsubtree to root's right,
        // then make root->right = root->left; (basically connect 5(whole subtree) to 4's right)
        TreeNode *current = root;
        while(current !=NULL){
            // taking from root
            if(current->left!=NULL){
                // prev = 2(from eg 1)
                TreeNode*prev = current->left;
                while(prev->right!=NULL){
                    prev = prev->right;
                }
                // prev become 4 now, 4->left = NULL, 4->right=5's subtree
                prev->right = current->right;
                // now put the whole left to the right -- 1->left=NULL and 1->right = 2
                /*
                      1
                    /   \
                   Null  2
                        /  \
                       3    4
                           /  \
                        Null   5
                              /  \
                            Null  6
                */
                current->right = current->left;
                current->left = NULL;
            }
            current=current->right;
        }

    }
};