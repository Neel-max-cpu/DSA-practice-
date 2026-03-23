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
    bool check(vector<string>&v){
        int i = 0, j = v.size()-1;
        while(i<j){                        
            if(v[i]!=v[j]) {                
                return false;
            }
            i++; j--;
        }
        return true;
    }

    bool helper(TreeNode *root1, TreeNode*root2){        
        if(!root1 || !root2){
            // if both null return true else false
            return root1==root2;
        }

        if(root1->val != root2->val) return false;

        // go left(root1) and go right(root2)
        bool one = helper(root1->left, root2->right);
        // after returning go right(root1) and go left(root2)
        bool two = helper(root1->right, root2->left);

        // inorder traversal ---
        return one&&two;
    }

    bool isSymmetric(TreeNode* root) {     

        // brute ---
        /*   
        queue<TreeNode*>q;
        if(root)
            q.push(root);

        while(!q.empty()){
            int len = q.size();
            vector<string>v;
            for(int i=0; i<len; i++){
                TreeNode* curr = q.front();
                q.pop();                
                if(curr->left) {
                    q.push(curr->left);
                    int x = curr->left->val;
                    v.push_back(to_string(x));
                }
                else v.push_back("#");
                
                if(curr->right) {
                    q.push(curr->right);
                    int x = curr->right->val;
                    v.push_back(to_string(x));
                }
                else v.push_back("#");                
            }

            if(!check(v)) {                
                return false;
            }
        }
        return true;
        */

        // optimal ---
        // inorder traversal -- left, root, right (on root's left) and right, root, left(on root's right) should
        // be same
        return root == NULL || helper(root->left, root->right);
    }
};