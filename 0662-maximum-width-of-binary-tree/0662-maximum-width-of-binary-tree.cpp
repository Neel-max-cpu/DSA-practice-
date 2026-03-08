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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>>q;
        if(root) q.push({root, 0});
        int ans = 0;

        while(!q.empty()){
            int len = q.size();
            int count = 0;           
            long long int left = 0;
            long long int right = 0;  

            //min index -- index of the first node at this level
            int minIndex = q.front().second;   

            for(int i=0; i<len; i++){
                auto a = q.front();
                q.pop();
                TreeNode *curr = a.first;
                long long int index = a.second;  
                // normalize index --
                long long int normalizeIndex = index - minIndex;                          

                if(i==0){
                    // relative index to avoid overflow --
                    /*
                    Width only depends on:
                    right - left
                    Subtracting a constant from both doesn't 
                    change the difference
                    */
                    left = normalizeIndex;
                }
                if(i==len-1){
                    // same normalize ---
                    right = normalizeIndex;
                }

                if(curr->left){
                    long long int idx = 2*normalizeIndex;
                    q.push({curr->left, idx});
                }
                if(curr->right){
                    long long int idx = 2*normalizeIndex+1;
                    q.push({curr->right, idx});
                }
            }

            int width = (right-left)+1;            
            ans = max(ans, width);
        }
        return ans;
    }
};