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
 
// const unsigned int mod = 1e9+7;
long long mod = 1e11;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,1});
        // left child would be 2*parentindex and right child would be 2*parentindex+1;
        
        long long int ans = 0;
        while(!q.empty()){
            long long len = q.size();
            long long starting;
            long long ending;
            for(int i=0; i<len; i++){
                auto p = q.front();
                q.pop();
                if(i==0){
                    starting = p.second;
                }
                if(i==len-1){
                    ending = p.second;
                }
                
                if(p.first->left != NULL){
                    // left child
                    long long x = (2*p.second)%mod;
                    q.push({p.first->left, x});                    
                }
                if(p.first->right!=NULL){
                    // right child
                    long long x = (2* p.second+1)%mod;
                    q.push({p.first->right, x});
                }                
            }    
            ans = max(ans, ending-starting+1);
        }
        return ans;
    }
};