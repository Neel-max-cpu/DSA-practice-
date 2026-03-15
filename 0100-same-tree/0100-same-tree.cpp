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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>one;
        queue<TreeNode*>two;

        if(p) one.push(p);
        if(q) two.push(q);

        while(!one.empty() && !two.empty()){
            int len1 = one.size();
            int len2 = two.size();

            if(len1 != len2) {
                cout<<"size not same!"<<endl;
                return false;
            }
            for(int i=0; i<len1; i++){
                TreeNode *x = one.front();
                TreeNode *y = two.front();
                one.pop();
                two.pop();

                if(x->val != y->val) {
                    cout<<"val not same!"<<endl;
                    return false;
                }

                int left = 0;
                if(x->left){
                    one.push(x->left);
                    left++;
                }
                if(y->left){
                    left++;
                    two.push(y->left);                                
                }                

                int right = 0;
                if(x->right){
                    right++;
                    one.push(x->right);
                }
                if(y->right){
                    right++;
                    two.push(y->right);                                
                }

                
                if(left==1 || right == 1){
                    return false;
                }
            }
        }

        if(!one.empty() || !two.empty()) {
            cout<<"one/two is not empty!"<<endl;
            return false;
        }
        else return true;
    }
};