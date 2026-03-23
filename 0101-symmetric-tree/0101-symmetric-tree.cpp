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

    bool isSymmetric(TreeNode* root) {        
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
    }
};