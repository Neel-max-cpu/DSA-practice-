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
        // mulitset allows duplicates and stores them in ascending order
        // we need in **column>row>value sorted order
        // eg -- we start from column 0, row 0 (can go -1,1 in column) and row increases by 1
        // eg 10 is at 0 column and row = 1 and another 5 at column 0 but row = 3 then we will have 10,5(not 5,10)
        // but if we have 10 at 0column and row 1 and another 5 at col 0 and row =1 then value sorted i.e 5,10
        
        // so in map - first col, then row, then values sorted
        map<int, map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        if(root){
            q.push({root, {0,0}});
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode *curr = p.first;
            // column
            int col = p.second.first;
            // row 
            int row = p.second.second;

            // insert 
            m[col][row].insert(curr->val);

            if(curr->left){
                q.push({curr->left, {col-1, row+1}});
            } 

            if(curr->right){
                q.push({curr->right, {col+1, row+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto it:m){
            vector<int>v;
            for(auto x:it.second){
                // insert multiset in vector
                v.insert(v.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};