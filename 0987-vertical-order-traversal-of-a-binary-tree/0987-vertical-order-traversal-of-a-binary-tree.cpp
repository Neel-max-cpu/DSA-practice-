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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // similar to top view/bottom view just 1more index is being added
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<pair<TreeNode*,pair<int,int>>>q;
        // since root is 0,0
        q.push({root, {0, 0}});
        /*            
        not visualize like the question -- 
                3(0,0)
               /  \ 
        (-1,1)9   20(1,1)
                 /  \
           (0,2)15   7(2,2)
        */

        // A multiset as the value, which can hold multiple integers, including duplicates, in sorted order(increasing default).
        //  multiset<int, greater<int> > -- decreasing
        map<int,map<int,multiset<int>>>m;

        while(!q.empty()){
            // automatically dedeuce the data structure
            auto p = q.front();
            q.pop();
            
            TreeNode *current = p.first;
            int x = p.second.first;
            int y = p.second.second;

            m[x][y].insert(current->val);

            if(current->left != NULL){
                q.push({current->left,{x-1, y+1}});                
            }
            if(current->right!=NULL){
                q.push({current->right,{x+1, y+1}});                
            }
        }

        for(auto it:m){
            vector<int>col;    
            // move to second since int,multiset        
            for(auto x:it.second){
                // x.second cause second is multiset
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};