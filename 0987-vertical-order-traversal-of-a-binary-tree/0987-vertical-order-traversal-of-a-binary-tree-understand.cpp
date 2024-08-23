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

        // level order traversal
        while(!q.empty()){
            // automatically dedeuce the data structure
            auto p = q.front();
            q.pop();
            
            TreeNode *current = p.first;
            int x = p.second.first;
            int y = p.second.second;

            m[x][y].insert(current->val);

            if(current->left != NULL){
                // we want the vector to have verticall
                q.push({current->left,{x-1, y+1}});    
                
                // we we do this we will get horizontally same col like 9,20 are in the same 1 but col is -1,1
                // similarly 15,7 in the same 
                /*
                basically the vector will be like this
                ----->
                ----->
                ----->

                but we want the vector to be like this --
                |  |  |
                |  |  |
                |  |  |
                |  |  |
                ↓  ↓  ↓
                */          
                // q.push({current->left,{x+1, y-1}});                
            }
            if(current->right!=NULL){
                q.push({current->right,{x+1, y+1}});                
                // q.push({current->right,{x+1, y+1}});                
            }
        }
        

        /*
            -1: {1: {9}},               // Vertical distance -1: Level 1 -> Node 9
            0: {0: {3}, 2: {15}},      // Vertical distance 0: Level 0 -> Node 3, Level 2 -> Node 15
            1: {1: {20}},              // Vertical distance 1: Level 1 -> Node 20
            2: {2: {7}}                  
        */
        for(auto it:m){
            vector<int>col;    
            // move to second since int,multiset        
            for(auto x:it.second){
                // and we have to push all the elements of each key 1 key might have mulitple multisets
                // x.second cause second is multiset

                //syntax =  vector_name.insert(position, iterator1, iterator2)
                // since let say 0 ->1 = {} and 0->2={} and 0->3={} then i have to put all the values of 0 in the vector 
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};